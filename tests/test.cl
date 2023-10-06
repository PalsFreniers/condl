$ ??add "std"
a* ? 5 : 0
.loop
a* ? a - 1 : 0
a >= 0 && l* ? .loop : ret
#1* ? 0 : 0
$ ??exit
