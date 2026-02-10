	.section .rodata
    .global Image
    .global ImageEnd

Image::
	.incbin "payload/payload.gba.lz"
ImageEnd::
