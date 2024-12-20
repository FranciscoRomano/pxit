// // -------------------------------------------------------------------------------------------------------------------------- //
// // SPDX-License-Identifier: MIT
// // Copyright (c) 2024 Francisco Romano
// // -------------------------------------------------------------------------------------------------------------------------- //
// #include "gles.h"
// #define GENERATE_FUNCTION_00(A, B)\
// A B() { return _gles.B(); }
// #define GENERATE_FUNCTION_01(A,B,C,D)\
// A B(C D) { return _gles.B(D); }
// #define GENERATE_FUNCTION_02(A,B,C,D,E,F)\
// A B(C D,E F) { return _gles.B(D,F); }
// #define GENERATE_FUNCTION_03(A,B,C,D,E,F,G,H)\
// A B(C D,E F,G H) { return _gles.B(D,F,H); }
// #define GENERATE_FUNCTION_04(A,B,C,D,E,F,G,H,I,J)\
// A B(C D,E F,G H,I J) { return _gles.B(D,F,H,J); }
// #define GENERATE_FUNCTION_05(A,B,C,D,E,F,G,H,I,J,K,L)\
// A B(C D,E F,G H,I J,K L) { return _gles.B(D,F,H,J,L); }
// #define GENERATE_FUNCTION_06(A,B,C,D,E,F,G,H,I,J,K,L,M,N)\
// A B(C D,E F,G H,I J,K L,M N) { return _gles.B(D,F,H,J,L,N); }
// #define GENERATE_FUNCTION_07(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P)\
// A B(C D,E F,G H,I J,K L,M N,O P) { return _gles.B(D,F,H,J,L,N,P); }
// #define GENERATE_FUNCTION_08(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R)\
// A B(C D,E F,G H,I J,K L,M N,O P,Q R) { return _gles.B(D,F,H,J,L,N,P,R); }
// #define GENERATE_FUNCTION_09(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T)\
// A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T) { return _gles.B(D,F,H,J,L,N,P,R,T); }
// #define GENERATE_FUNCTION_10(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V)\
// A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T,U V) { return _gles.B(D,F,H,J,L,N,P,R,T,V); }
// #define GENERATE_FUNCTION_11(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X)\
// A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T,U V,W X) { return _gles.B(D,F,H,J,L,N,P,R,T,V,X); }
// #define GENERATE_FUNCTION_12(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z)\
// A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T,U V,W X,Y Z) { return _gles.B(D,F,H,J,L,N,P,R,T,V,X,Z); }
// // -------------------------------------------------------------------------------------------------------------------------- //
// GENERATE_FUNCTION_00(void, glBlendBarrier)
// GENERATE_FUNCTION_00(void, glCopyImageSubData, GLuint, srcName, GLenum, srcTarget, GLint, srcLevel, GLint, srcX, GLint, srcY, GLint, srcZ, GLuint, dstName, GLenum, dstTarget, GLint, dstLevel, GLint, dstX, GLint, dstY, GLint, dstZ, GLsizei, srcWidth, GLsizei, srcHeight, GLsizei, srcDepth)
// GENERATE_FUNCTION_00(void, glDebugMessageControl, GLenum, source, GLenum, type, GLenum, severity, GLsizei, count, const GLuint*, ids, GLboolean, enabled)
// GENERATE_FUNCTION_00(void, glDebugMessageInsert, GLenum, source, GLenum, type, GLuint, id, GLenum, severity, GLsizei, length, const GLchar*, buf)
// GENERATE_FUNCTION_00(void, glDebugMessageCallback, GLDEBUGPROC, callback, const void*, userParam)
// GENERATE_FUNCTION_00(GLuint, glGetDebugMessageLog, GLuint, count, GLsizei, bufSize, GLenum*, sources, GLenum*, types, GLuint*, ids, GLenum*, severities, GLsizei*, lengths, GLchar*, messageLog)
// GENERATE_FUNCTION_00(void, glPushDebugGroup, GLenum, source, GLuint, id, GLsizei, length, const GLchar*, message)
// GENERATE_FUNCTION_00(void, glPopDebugGroup)
// GENERATE_FUNCTION_00(void, glObjectLabel, GLenum, identifier, GLuint, name, GLsizei, length, const GLchar*, label)
// GENERATE_FUNCTION_00(void, glGetObjectLabel, GLenum, identifier, GLuint, name, GLsizei, bufSize, GLsizei*, length, GLchar*, label)
// GENERATE_FUNCTION_00(void, glObjectPtrLabel, const void*, ptr, GLsizei, length, const GLchar*, label)
// GENERATE_FUNCTION_00(void, glGetObjectPtrLabel, const void*, ptr, GLsizei, bufSize, GLsizei*, length, GLchar*, label)
// GENERATE_FUNCTION_00(void, glGetPointerv, GLenum, pname, void**, params)
// GENERATE_FUNCTION_00(void, glEnablei, GLenum, target, GLuint, index)
// GENERATE_FUNCTION_00(void, glDisablei, GLenum, target, GLuint, index)
// GENERATE_FUNCTION_00(void, glBlendEquationi, GLuint, buf, GLenum, mode)
// GENERATE_FUNCTION_00(void, glBlendEquationSeparatei, GLuint, buf, GLenum, modeRGB, GLenum, modeAlpha)
// GENERATE_FUNCTION_00(void, glBlendFunci, GLuint, buf, GLenum, src, GLenum, dst)
// GENERATE_FUNCTION_00(void, glBlendFuncSeparatei, GLuint, buf, GLenum, srcRGB, GLenum, dstRGB, GLenum, srcAlpha, GLenum, dstAlpha)
// GENERATE_FUNCTION_00(void, glColorMaski, GLuint, index, GLboolean, r, GLboolean, g, GLboolean, b, GLboolean, a)
// GENERATE_FUNCTION_00(GLboolean, glIsEnabledi, GLenum, target, GLuint, index)
// GENERATE_FUNCTION_00(void, glDrawElementsBaseVertex, GLenum, mode, GLsizei, count, GLenum, type, const void*, indices, GLint, basevertex)
// GENERATE_FUNCTION_00(void, glDrawRangeElementsBaseVertex, GLenum, mode, GLuint, start, GLuint, end, GLsizei, count, GLenum, type, const void*, indices, GLint, basevertex)
// GENERATE_FUNCTION_00(void, glDrawElementsInstancedBaseVertex, GLenum, mode, GLsizei, count, GLenum, type, const void*, indices, GLsizei, instancecount, GLint, basevertex)
// GENERATE_FUNCTION_00(void, glFramebufferTexture, GLenum, target, GLenum, attachment, GLuint, texture, GLint, level)
// GENERATE_FUNCTION_00(void, glPrimitiveBoundingBox, GLfloat, minX, GLfloat, minY, GLfloat, minZ, GLfloat, minW, GLfloat, maxX, GLfloat, maxY, GLfloat, maxZ, GLfloat, maxW)
// GENERATE_FUNCTION_00(GLenum, glGetGraphicsResetStatus)
// GENERATE_FUNCTION_00(void, glReadnPixels, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, GLsizei, bufSize, void*, data)
// GENERATE_FUNCTION_00(void, glGetnUniformfv, GLuint, program, GLint, location, GLsizei, bufSize, GLfloat*, params)
// GENERATE_FUNCTION_00(void, glGetnUniformiv, GLuint, program, GLint, location, GLsizei, bufSize, GLint*, params)
// GENERATE_FUNCTION_00(void, glGetnUniformuiv, GLuint, program, GLint, location, GLsizei, bufSize, GLuint*, params)
// GENERATE_FUNCTION_00(void, glMinSampleShading, GLfloat, value)
// GENERATE_FUNCTION_00(void, glPatchParameteri, GLenum, pname, GLint, value)
// GENERATE_FUNCTION_00(void, glTexParameterIiv, GLenum, target, GLenum, pname, const GLint*, params)
// GENERATE_FUNCTION_00(void, glTexParameterIuiv, GLenum, target, GLenum, pname, const GLuint*, params)
// GENERATE_FUNCTION_00(void, glGetTexParameterIiv, GLenum, target, GLenum, pname, GLint*, params)
// GENERATE_FUNCTION_00(void, glGetTexParameterIuiv, GLenum, target, GLenum, pname, GLuint*, params)
// GENERATE_FUNCTION_00(void, glSamplerParameterIiv, GLuint, sampler, GLenum, pname, const GLint*, param)
// GENERATE_FUNCTION_00(void, glSamplerParameterIuiv, GLuint, sampler, GLenum, pname, const GLuint*, param)
// GENERATE_FUNCTION_00(void, glGetSamplerParameterIiv, GLuint, sampler, GLenum, pname, GLint*, params)
// GENERATE_FUNCTION_00(void, glGetSamplerParameterIuiv, GLuint, sampler, GLenum, pname, GLuint*, params)
// GENERATE_FUNCTION_00(void, glTexBuffer, GLenum, target, GLenum, internalformat, GLuint, buffer)
// GENERATE_FUNCTION_00(void, glTexBufferRange, GLenum, target, GLenum, internalformat, GLuint, buffer, GLintptr, offset, GLsizeiptr, size)
// GENERATE_FUNCTION_00(void, glTexStorage3DMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLboolean, fixedsamplelocations)