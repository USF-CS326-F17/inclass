#define BUF_SIZE 32
char buffer[BUF_SIZE];
int buflen = BUF_SIZE;
int bufpos = BUF_SIZE;

int get_line_buffered(int fd, char *line)
{
    int count = 0;
    
    while (1) {
        if (buflen != BUF_SIZE && buflen == bufpos) { /* BBB */
            break;
        }

        /* Need to read a chunk? */
        if (bufpos == BUF_SIZE) {
            buflen = read(fd, buffer, BUF_SIZE);
			
            if (buflen < 0) { 
                return buflen;
            }
            if (buflen == 0) { /* AAA */
                break;
            }
            bufpos = 0;
        }
        
        line[count] = buffer[bufpos];
        count += 1;
        bufpos += 1;
        
        if (buffer[bufpos-1] == '\n') {
            break;
        }

        if (count == MAX_LINE_LEN) {
            count = -1;
            break;
        }
    }
    
    line[count] = '\0';
    
    return count;
}
