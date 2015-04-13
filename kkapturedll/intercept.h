/* kkapture: intrusive demo video capturing.
 * Copyright (c) 2005-2010 Fabian "ryg/farbrausch" Giesen.
 *
 * This program is free software; you can redistribute and/or modify it under
 * the terms of the Artistic License, Version 2.0beta5, or (at your opinion)
 * any later version; all distributions of this program should contain this
 * license in a file named "LICENSE.txt".
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT UNLESS REQUIRED BY
 * LAW OR AGREED TO IN WRITING WILL ANY COPYRIGHT HOLDER OR CONTRIBUTOR
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __INTERCEPT_H__
#define __INTERCEPT_H__

#ifdef _USRDLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

enum ErrorCodes
{
  ERR_OK = 0,
  ERR_INSTRUMENTATION_FAILED,
  ERR_COULDNT_EXECUTE
};

extern BOOL (__stdcall *Real_CreateProcessA)(LPCSTR appName,LPSTR cmdLine,LPSECURITY_ATTRIBUTES processAttr,LPSECURITY_ATTRIBUTES threadAttr,BOOL inheritHandles,DWORD flags,LPVOID env,LPCSTR currentDir,LPSTARTUPINFOA startupInfo,LPPROCESS_INFORMATION processInfo);
extern BOOL (__stdcall *Real_CreateProcessW)(LPCWSTR appName,LPWSTR cmdLine,LPSECURITY_ATTRIBUTES processAttr,LPSECURITY_ATTRIBUTES threadAttr,BOOL inheritHandles,DWORD flags,LPVOID env,LPCWSTR currentDir,LPSTARTUPINFOW startupInfo,LPPROCESS_INFORMATION processInfo);

extern "C" DLLEXPORT int CreateInstrumentedProcessA(LPCSTR appName,LPSTR cmdLine,
  LPSECURITY_ATTRIBUTES processAttr,LPSECURITY_ATTRIBUTES threadAttr,BOOL inheritHandles,DWORD flags,
  LPVOID env,LPCSTR currentDir,LPSTARTUPINFO startupInfo,LPPROCESS_INFORMATION pi);

extern "C" DLLEXPORT int CreateInstrumentedProcessW(LPCWSTR appName,LPWSTR cmdLine,
  LPSECURITY_ATTRIBUTES processAttr,LPSECURITY_ATTRIBUTES threadAttr,BOOL inheritHandles,DWORD flags,
  LPVOID env,LPCWSTR currentDir,LPSTARTUPINFOW startupInfo,LPPROCESS_INFORMATION pi);

void initProcessIntercept();

#endif