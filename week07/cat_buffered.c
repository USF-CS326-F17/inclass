#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define BUF_SIZE 32
char buffer[BUF_SIZE];
int buflen = BUF_SIZE;
int bufpos = BUF_SIZE;

struct buffer {
    char *data;
    int fd;
    int size;
    int len;
    int pos;
};

struct buffer *new_buffer(int fd, int size)
{
    struct buffer *b;

    b = (struct buffer *) malloc(sizeof(struct buffer));
    if (b == NULL) {
        printf("malloc failed, exiting\n");
        exit(-1);
    }

    b->data = (char *) malloc(size);
    if (b->data == NULL) {
        printf("malloc failed, exiting\n");
        exit(-1);
    }

    b->fd = fd;
    b->size = size;
    b->len = size;
    b->pos = size;

    return b;
}

void buffer_free(struct buffer *b)
{
    free(b->data);
    free(b);
}


int buffer_readline(struct buffer *b, char *line, int len)
{
    int count = 0;
    
    while (1) {
        if (b->len != b->size && b->len == b->pos) {
            break;
        }

        /* Need to read a chunk? */
        if (b->pos == b->size) {
            b->len = read(b->fd, b->data, b->size);
			
            if (b->len < 0) { 
                return b->len;
            }
            if (b->len == 0) {
                break;
            }
            b->pos = 0;
        }
        
        line[count] = b->data[b->pos];
        count += 1;
        b->pos += 1;
        
        if (b->data[b->pos-1] == '\n') {
            break;
        }

        if (count == len) {
            count = -1;
            return count;
        }
    }
    
    line[count] = '\0';
    
    return count;
}

int main(int argc, char **argv)
{
    int fd;
    struct buffer *buf;
    int rv;
    char line[512];
    
    fd = open(argv[1], O_RDONLY);
    buf = new_buffer(fd, 4096);

    while((rv = buffer_readline(buf, line, 512)) > 0) {
        printf("%s", line);
    }

    buffer_free(buf);
    close(fd);

    return 0;
}
    
