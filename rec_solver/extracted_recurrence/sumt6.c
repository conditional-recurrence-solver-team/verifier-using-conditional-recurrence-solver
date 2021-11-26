SIZE = 20000001;
n = tmp0;
i = 0;
k = 0;
j = 0;
l = 0;
v2 = 0;
v3 = 0;
v4 = 0;

if (l % 6 == 0) {
v2 = v2 + 1;
l = l + 1;
j = j;
v4 = v4;
i = i;
v3 = v3;
k = k;
} else if (l % 5 == 0) {
v3 = v3 + 1;
l = l + 1;
j = j;
v2 = v2;
v4 = v4;
i = i;
k = k;
} else if (l % 4 == 0) {
v4 = v4 + 1;
l = l + 1;
j = j;
v2 = v2;
i = i;
v3 = v3;
k = k;
} else if (l % 3 == 0) {
i = i + 1;
l = l + 1;
j = j;
v2 = v2;
v4 = v4;
v3 = v3;
k = k;
} else if (l % 2 == 0) {
j = j + 1;
k = k;
l = l + 1;
v2 = v2;
v4 = v4;
i = i;
v3 = v3;
} else {
k = k + 1;
j = j;
l = l + 1;
v2 = v2;
v4 = v4;
i = i;
v3 = v3;
}