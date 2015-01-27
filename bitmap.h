#include <iostream>

using namespace std;

struct bitmap
	{
	struct bmpHeader //Contains info about the file
	{
	char signature[1] ; //File signature/magic number usually BM for bitmap
	char fileSize[3] ; //Size of entire file
	char researved1[1]; //Not used
	char researved2[1]; //Not used
	char bmpOffset[3]; //Offset to pixel data
	}
	struct dibHeader //Bitmap info
	{
		struct BITMAPINFOHEADER //Start of info header
		{
		char headerSize[3]; //Size this header
		char bmpWidth[3]; //Width of Bitmap
		char bmpHeight[3]; //Height of Bitmap
		char colorPlanes[3]; //color planes...usually 1
		char bitsPerPx[1]; //Number of bits per pixel , 1 bit is mono-color/mono-chrome
		char compression[3]; //Compression scheme used ...not using any
		char imageSize[3]; //Pixel data size
		horizontalRez[3]; // Just what you think it would be
		verticalRez[3]; // Ditto
		char colorsPalette[3]; //Colors in pallet
		char importantColors[3]; // 0 = all important
		}
		}
	}
