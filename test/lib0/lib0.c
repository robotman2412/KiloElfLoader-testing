
int c = 256;

int foobar() {
	return 512;
}

static void constructor() __attribute__((constructor));
static void constructor() {
	c = 128;
}

static void destructor() __attribute__((destructor));
static void destructor() {
	c = 512;
}
