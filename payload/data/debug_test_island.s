#ifdef DEBUG_TEST
#define DEBUG_TEST_ISLAND_PATH "../assets/debug/test_island_agb_fmt.bin"
	.section .debug_test_island,"a",%progbits
	.balign 4
	.global gDebugTestIsland
gDebugTestIsland:
	.incbin DEBUG_TEST_ISLAND_PATH
#endif
