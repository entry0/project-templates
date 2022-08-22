ENTRY(_start)
PHDRS
{
   segment PT_LOAD FLAGS (7); /* RWX */
}
SECTIONS
{
	. = SEGMENT_START("text-segment", 0x400000) + SIZEOF_HEADERS;

	.text : { *(.text); } : segment
}
