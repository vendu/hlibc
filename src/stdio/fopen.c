#include "../internal/internal.h"

FILE *fopen(const char *name, const char *mode)
{
	int fd = 0;
	FILE *fp;
	int perms = 0666; // not yet used
	const char *p = mode;
	int outfile = 0;
	int seek = -1;


	for (fp = _IO_stream; fp < _IO_stream + FOPEN_MAX; fp++) {
		if (fp->read == 0 || fp->write == 0) {
			break;
		}
	}
	if (fp >= _IO_stream + FOPEN_MAX) {
		return NULL;
	}

	/* initialize the FILE pointer to _IO_stream[N] */
	fp->write = 0;
	fp->read = 0;
	fp->lnbuf = 0;
	fp->unbuf = 0;
	fp->err = 0;
	fp->eof = 0;

	while (*p) {
		switch (*p++) {
		case 'r':
			outfile |= O_RDONLY;
			fp->read = 1;
			switch (*p) {
			case '+':
				outfile |= O_RDWR;
				fp->write = 1;
				break;
			default:
				break;
			}
			break;
		case 'w':
			outfile = O_TRUNC | O_CREAT | O_RDWR;
			fp->write = 1;
			switch (*p) {
			case '+':
				outfile &= ~O_TRUNC; 
				seek = SEEK_END;
				break;
			default:
				break;
			}
			break;
		case 'a':
			outfile = O_CREAT | O_APPEND;
			fp->write = 1;
			switch (*p) {
			case '+':
				outfile |= O_RDWR;
				fp->read = 1;
				fp->write = 1;
				break;
			default:
				break;
			}
			seek = SEEK_END;
			break;
		default:
			return NULL;
		}
	}
	
	if (name != NULL) {
		if ((fd = open(name, outfile, perms)) == -1) {
			return NULL;
		}
	}

	if (seek == SEEK_END) {
		lseek(fd, 0L, seek);
	}

	fp->len = 0;
	fp->rp = fp->buf = NULL;
	fp->fd = fd;

	return fp;
}
