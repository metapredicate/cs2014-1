/* 
 * Copyright (c) 2017 stephen.farrell@cs.tcd.ie
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

// needed for getting access to /dev/random
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/random.h>

// TODO: check if conditional compile needed as per: https://stackoverflow.com/questions/30800331/getrandom-syscall-in-c-not-found

unsigned char rndbyte()
{
	unsigned long int s;
	syscall(SYS_getrandom, &s, sizeof(unsigned long int), 0);
	unsigned char byte=(s>>16)%256;
	return(byte);
}

int rndbytes(unsigned char* buf,int buflen)
{
	if (!buf) return(1);
	syscall(SYS_getrandom, buf, buflen, 0);
	return(0);
}

