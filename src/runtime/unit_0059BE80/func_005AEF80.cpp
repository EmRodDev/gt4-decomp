/* compiler: ee-gcc2.9-991111 */
/* Byte ring buffer header (data follows at +0x10), see func_005AEFA8. */
struct RingBuffer {
	int capacity;
	int count;
	char *readPos;
	char *writePos;
	char data[1];
};

extern "C" RingBuffer D_00886300;

extern "C" RingBuffer *func_005AEF80(int capacity)
{
	RingBuffer *rb = &D_00886300;
	rb->capacity = capacity;
	rb->count = 0;
	rb->writePos = rb->data;
	rb->readPos = rb->data;
	return rb;
}
