#include <file_utils.h>

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
