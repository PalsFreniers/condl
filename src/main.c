#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/types.h"
#define PLIBC_LOGGER_FUNC
#define PLIBC_LOGGER_STRUCT
#include "../includes/logger.h"

#define DEFER(x) {defer = x; goto defer;}


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
