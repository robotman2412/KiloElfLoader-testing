
extern int foobar();
extern int c;

int q;

extern void pront(const char *);

static void ok() {
	q = 3;
}

int _start() {
	pront("_start\n");
	return (c << 16) | q;
}
