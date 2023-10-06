#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>
#define PLIBC_LOGGER_FUNC
#define PLIBC_LOGGER_STRUCT
#include <logger.h>

#define DEFER(x) {defer = x; goto defer;}

char *slurp(FILE *f) {
        char *ret = NULL;
        if(!f) goto err;
        if(fseek(f, 0, SEEK_END)) goto err;
        i64 fSize = ftell(f) + 1;
        if(!fSize) goto err;
        ret = malloc(sizeof(char) * fSize);
        if(!ret) goto err;
        if(fseek(f, 0, SEEK_SET)) goto merr;
        u64 newL = fread(ret, sizeof(char), fSize, f);
        if(!newL) goto merr;
        ret[newL] = '\0';
        return ret;
merr:
        free(ret);
        ret = NULL;
err:
        Logger_error("Error during file slurp abort.");
        return ret;
}

int line(char *src, int num, char *dst) {
        int l = 0;
        int i = 0, j = 0;
        for(i = 0; src[i] != 0 && l < num; i++) if(src[i] == '\n') l++;
        if(src[i] == 0 || (src[i - 1] != '\n' && num != 0)) return 0;
        for(j = 0; src[i] != 0 && src[i] != '\n'; j++) {
                dst[j] = src[i];
                i++;
        }
        dst[j] = 0;
        return 1;
}

char *process(char *data) {
        char *ret = NULL;
        // remove comments
        int newLen = 0;
        int inCom = 0;
        for(int i = 0; data[i]; i++) {
                if(data[i] == '$') inCom = 1;
                if(!inCom) newLen++;
                if(data[i] == '\n') inCom = 0;
        }
        ret = malloc((newLen + 1) * sizeof(char));
        if(!ret) return NULL;
        int j = 0;
        for(int i = 0; data[i]; i++) {
                if(data[i] == '$') inCom = 1;
                if(!inCom) {
                        ret[j] = data[i];
                        j++;
                }
                if(data[i] == '\n') inCom = 0;
        }
        ret[j] = 0;
        // replace macros
        /// add macros
        /// other
        // handle labels
        data = ret;

        return ret;
}

int main(int c, char **v) {
        (void)c;
        FILE *f = fopen(v[1], "r");
        char *data = slurp(f);
        fclose(f);
        char *end = process(data);
        printf("%s", end);
        free(data);
        return 0;
}
