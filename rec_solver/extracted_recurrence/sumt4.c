SIZE = 20000001;
n = tmp0;
i = 0;
k = 0;
j = 0;
l = 0;
v4 = 0;

if (l % 4 == 0) {
v4 = v4 + 1;
l = l + 1;
j = j;
i = i;
k = k;
} else if (l % 3 == 0) {
i = i + 1;
l = l + 1;
j = j;
v4 = v4;
k = k;
} else if (l % 2 == 0) {
j = j + 1;
k = k;
l = l + 1;
v4 = v4;
i = i;
} else {
k = k + 1;
j = j;
l = l + 1;
v4 = v4;
i = i;
}