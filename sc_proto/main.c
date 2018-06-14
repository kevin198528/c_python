#include <stdio.h>
#include "./sc_proto.h"

int main(int argc, char ** argv)
{
	p_scanner_handle p_scanner = NULL;

	p_scanner = sc_scanner_create();

	printf("create scanner 0x%x\n", (unsigned int)p_scanner);

	sc_scanner_scan(p_scanner);

	sc_scanner_delete(p_scanner);

	return 0;
}
