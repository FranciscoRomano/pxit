// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "gles.h"
#define GENERATE_FUNCTION_00(A, B)\
A B() { return _gles.B(); }
#define GENERATE_FUNCTION_01(A,B,C,D)\
A B(C D) { return _gles.B(D); }
#define GENERATE_FUNCTION_02(A,B,C,D,E,F)\
A B(C D,E F) { return _gles.B(D,F); }
#define GENERATE_FUNCTION_03(A,B,C,D,E,F,G,H)\
A B(C D,E F,G H) { return _gles.B(D,F,H); }
#define GENERATE_FUNCTION_04(A,B,C,D,E,F,G,H,I,J)\
A B(C D,E F,G H,I J) { return _gles.B(D,F,H,J); }
#define GENERATE_FUNCTION_05(A,B,C,D,E,F,G,H,I,J,K,L)\
A B(C D,E F,G H,I J,K L) { return _gles.B(D,F,H,J,L); }
#define GENERATE_FUNCTION_06(A,B,C,D,E,F,G,H,I,J,K,L,M,N)\
A B(C D,E F,G H,I J,K L,M N) { return _gles.B(D,F,H,J,L,N); }
#define GENERATE_FUNCTION_07(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P)\
A B(C D,E F,G H,I J,K L,M N,O P) { return _gles.B(D,F,H,J,L,N,P); }
#define GENERATE_FUNCTION_08(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R)\
A B(C D,E F,G H,I J,K L,M N,O P,Q R) { return _gles.B(D,F,H,J,L,N,P,R); }
#define GENERATE_FUNCTION_09(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T)\
A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T) { return _gles.B(D,F,H,J,L,N,P,R,T); }
#define GENERATE_FUNCTION_10(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V)\
A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T,U V) { return _gles.B(D,F,H,J,L,N,P,R,T,V); }
#define GENERATE_FUNCTION_11(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X)\
A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T,U V,W X) { return _gles.B(D,F,H,J,L,N,P,R,T,V,X); }
#define GENERATE_FUNCTION_12(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z)\
A B(C D,E F,G H,I J,K L,M N,O P,Q R,S T,U V,W X,Y Z) { return _gles.B(D,F,H,J,L,N,P,R,T,V,X,Z); }
// -------------------------------------------------------------------------------------------------------------------------- //
GENERATE_FUNCTION_01(void, glReadBuffer, GLenum, src)
GENERATE_FUNCTION_06(void, glDrawRangeElements, GLenum, mode, GLuint, start, GLuint, end, GLsizei, count, GLenum, type, const void*, indices)
GENERATE_FUNCTION_10(void, glTexImage3D, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLenum, format, GLenum, type, const void*, pixels)
GENERATE_FUNCTION_11(void, glTexSubImage3D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLenum, type, const void*, pixels)
GENERATE_FUNCTION_09(void, glCopyTexSubImage3D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height)
GENERATE_FUNCTION_09(void, glCompressedTexImage3D, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLsizei, imageSize, const void*, data)
GENERATE_FUNCTION_11(void, glCompressedTexSubImage3D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLsizei, imageSize, const void*, data)
GENERATE_FUNCTION_02(void, glGenQueries, GLsizei, n, GLuint*, ids)
GENERATE_FUNCTION_02(void, glDeleteQueries, GLsizei, n, const GLuint*, ids)
GENERATE_FUNCTION_01(GLboolean, glIsQuery, GLuint, id)
GENERATE_FUNCTION_02(void, glBeginQuery, GLenum, target, GLuint, id)
GENERATE_FUNCTION_01(void, glEndQuery, GLenum, target)
GENERATE_FUNCTION_03(void, glGetQueryiv, GLenum, target, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_03(void, glGetQueryObjectuiv, GLuint, id, GLenum, pname, GLuint*, params)
GENERATE_FUNCTION_01(GLboolean, glUnmapBuffer, GLenum, target)
GENERATE_FUNCTION_03(void, glGetBufferPointerv, GLenum, target, GLenum, pname, void**, params)
GENERATE_FUNCTION_02(void, glDrawBuffers, GLsizei, n, const GLenum*, bufs)
GENERATE_FUNCTION_04(void, glUniformMatrix2x3fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glUniformMatrix3x2fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glUniformMatrix2x4fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glUniformMatrix4x2fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glUniformMatrix3x4fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glUniformMatrix4x3fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_10(void, glBlitFramebuffer, GLint, srcX0, GLint, srcY0, GLint, srcX1, GLint, srcY1, GLint, dstX0, GLint, dstY0, GLint, dstX1, GLint, dstY1, GLbitfield, mask, GLenum, filter)
GENERATE_FUNCTION_05(void, glRenderbufferStorageMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height)
GENERATE_FUNCTION_05(void, glFramebufferTextureLayer, GLenum, target, GLenum, attachment, GLuint, texture, GLint, level, GLint, layer)
GENERATE_FUNCTION_04(void*, glMapBufferRange, GLenum, target, GLintptr, offset, GLsizeiptr, length, GLbitfield, access)
GENERATE_FUNCTION_03(void, glFlushMappedBufferRange, GLenum, target, GLintptr, offset, GLsizeiptr, length)
GENERATE_FUNCTION_01(void, glBindVertexArray, GLuint, array)
GENERATE_FUNCTION_02(void, glDeleteVertexArrays, GLsizei, n, const GLuint*, arrays)
GENERATE_FUNCTION_02(void, glGenVertexArrays, GLsizei, n, GLuint*, arrays)
GENERATE_FUNCTION_01(GLboolean, glIsVertexArray, GLuint, array)
GENERATE_FUNCTION_03(void, glGetIntegeri_v, GLenum, target, GLuint, index, GLint*, data)
GENERATE_FUNCTION_01(void, glBeginTransformFeedback, GLenum, primitiveMode)
GENERATE_FUNCTION_00(void, glEndTransformFeedback)
GENERATE_FUNCTION_05(void, glBindBufferRange, GLenum, target, GLuint, index, GLuint, buffer, GLintptr, offset, GLsizeiptr, size)
GENERATE_FUNCTION_03(void, glBindBufferBase, GLenum, target, GLuint, index, GLuint, buffer)
GENERATE_FUNCTION_04(void, glTransformFeedbackVaryings, GLuint, program, GLsizei, count, const GLchar*const*, varyings, GLenum, bufferMode)
GENERATE_FUNCTION_07(void, glGetTransformFeedbackVarying, GLuint, program, GLuint, index, GLsizei, bufSize, GLsizei*, length, GLsizei*, size, GLenum*, type, GLchar*, name)
GENERATE_FUNCTION_05(void, glVertexAttribIPointer, GLuint, index, GLint, size, GLenum, type, GLsizei, stride, const void*, pointer)
GENERATE_FUNCTION_03(void, glGetVertexAttribIiv, GLuint, index, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_03(void, glGetVertexAttribIuiv, GLuint, index, GLenum, pname, GLuint*, params)
GENERATE_FUNCTION_05(void, glVertexAttribI4i, GLuint, index, GLint, x, GLint, y, GLint, z, GLint, w)
GENERATE_FUNCTION_05(void, glVertexAttribI4ui, GLuint, index, GLuint, x, GLuint, y, GLuint, z, GLuint, w)
GENERATE_FUNCTION_02(void, glVertexAttribI4iv, GLuint, index, const GLint*, v)
GENERATE_FUNCTION_02(void, glVertexAttribI4uiv, GLuint, index, const GLuint*, v)
GENERATE_FUNCTION_03(void, glGetUniformuiv, GLuint, program, GLint, location, GLuint*, params)
GENERATE_FUNCTION_02(GLint, glGetFragDataLocation, GLuint, program, const GLchar*, name)
GENERATE_FUNCTION_02(void, glUniform1ui, GLint, location, GLuint, v0)
GENERATE_FUNCTION_03(void, glUniform2ui, GLint, location, GLuint, v0, GLuint, v1)
GENERATE_FUNCTION_04(void, glUniform3ui, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2)
GENERATE_FUNCTION_05(void, glUniform4ui, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2, GLuint, v3)
GENERATE_FUNCTION_03(void, glUniform1uiv, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_03(void, glUniform2uiv, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_03(void, glUniform3uiv, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_03(void, glUniform4uiv, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_03(void, glClearBufferiv, GLenum, buffer, GLint, drawbuffer, const GLint*, value)
GENERATE_FUNCTION_03(void, glClearBufferuiv, GLenum, buffer, GLint, drawbuffer, const GLuint*, value)
GENERATE_FUNCTION_03(void, glClearBufferfv, GLenum, buffer, GLint, drawbuffer, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glClearBufferfi, GLenum, buffer, GLint, drawbuffer, GLfloat, depth, GLint, stencil)
GENERATE_FUNCTION_02(const GLubyte*, glGetStringi, GLenum, name, GLuint, index)
GENERATE_FUNCTION_05(void, glCopyBufferSubData, GLenum, readTarget, GLenum, writeTarget, GLintptr, readOffset, GLintptr, writeOffset, GLsizeiptr, size)
GENERATE_FUNCTION_04(void, glGetUniformIndices, GLuint, program, GLsizei, uniformCount, const GLchar*const*, uniformNames, GLuint*, uniformIndices)
GENERATE_FUNCTION_05(void, glGetActiveUniformsiv, GLuint, program, GLsizei, uniformCount, const GLuint*, uniformIndices, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_02(GLuint, glGetUniformBlockIndex, GLuint, program, const GLchar*, uniformBlockName)
GENERATE_FUNCTION_04(void, glGetActiveUniformBlockiv, GLuint, program, GLuint, uniformBlockIndex, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_05(void, glGetActiveUniformBlockName, GLuint, program, GLuint, uniformBlockIndex, GLsizei, bufSize, GLsizei*, length, GLchar*, uniformBlockName)
GENERATE_FUNCTION_03(void, glUniformBlockBinding, GLuint, program, GLuint, uniformBlockIndex, GLuint, uniformBlockBinding)
GENERATE_FUNCTION_04(void, glDrawArraysInstanced, GLenum, mode, GLint, first, GLsizei, count, GLsizei, instancecount)
GENERATE_FUNCTION_05(void, glDrawElementsInstanced, GLenum, mode, GLsizei, count, GLenum, type, const void*, indices, GLsizei, instancecount)
GENERATE_FUNCTION_02(GLsync, glFenceSync, GLenum, condition, GLbitfield, flags)
GENERATE_FUNCTION_01(GLboolean, glIsSync, GLsync, sync)
GENERATE_FUNCTION_01(void, glDeleteSync, GLsync, sync)
GENERATE_FUNCTION_03(GLenum, glClientWaitSync, GLsync, sync, GLbitfield, flags, GLuint64, timeout)
GENERATE_FUNCTION_03(void, glWaitSync, GLsync, sync, GLbitfield, flags, GLuint64, timeout)
GENERATE_FUNCTION_02(void, glGetInteger64v, GLenum, pname, GLint64*, data)
GENERATE_FUNCTION_05(void, glGetSynciv, GLsync, sync, GLenum, pname, GLsizei, bufSize, GLsizei*, length, GLint*, values)
GENERATE_FUNCTION_03(void, glGetInteger64i_v, GLenum, target, GLuint, index, GLint64*, data)
GENERATE_FUNCTION_03(void, glGetBufferParameteri64v, GLenum, target, GLenum, pname, GLint64*, params)
GENERATE_FUNCTION_02(void, glGenSamplers, GLsizei, count, GLuint*, samplers)
GENERATE_FUNCTION_02(void, glDeleteSamplers, GLsizei, count, const GLuint*, samplers)
GENERATE_FUNCTION_01(GLboolean, glIsSampler, GLuint, sampler)
GENERATE_FUNCTION_02(void, glBindSampler, GLuint, unit, GLuint, sampler)
GENERATE_FUNCTION_03(void, glSamplerParameteri, GLuint, sampler, GLenum, pname, GLint, param)
GENERATE_FUNCTION_03(void, glSamplerParameteriv, GLuint, sampler, GLenum, pname, const GLint*, param)
GENERATE_FUNCTION_03(void, glSamplerParameterf, GLuint, sampler, GLenum, pname, GLfloat, param)
GENERATE_FUNCTION_03(void, glSamplerParameterfv, GLuint, sampler, GLenum, pname, const GLfloat*, param)
GENERATE_FUNCTION_03(void, glGetSamplerParameteriv, GLuint, sampler, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_03(void, glGetSamplerParameterfv, GLuint, sampler, GLenum, pname, GLfloat*, params)
GENERATE_FUNCTION_02(void, glVertexAttribDivisor, GLuint, index, GLuint, divisor)
GENERATE_FUNCTION_02(void, glBindTransformFeedback, GLenum, target, GLuint, id)
GENERATE_FUNCTION_02(void, glDeleteTransformFeedbacks, GLsizei, n, const GLuint*, ids)
GENERATE_FUNCTION_02(void, glGenTransformFeedbacks, GLsizei, n, GLuint*, ids)
GENERATE_FUNCTION_01(GLboolean, glIsTransformFeedback, GLuint, id)
GENERATE_FUNCTION_00(void, glPauseTransformFeedback)
GENERATE_FUNCTION_00(void, glResumeTransformFeedback)
GENERATE_FUNCTION_05(void, glGetProgramBinary, GLuint, program, GLsizei, bufSize, GLsizei*, length, GLenum*, binaryFormat, void*, binary)
GENERATE_FUNCTION_04(void, glProgramBinary, GLuint, program, GLenum, binaryFormat, const void*, binary, GLsizei, length)
GENERATE_FUNCTION_03(void, glProgramParameteri, GLuint, program, GLenum, pname, GLint, value)
GENERATE_FUNCTION_03(void, glInvalidateFramebuffer, GLenum, target, GLsizei, numAttachments, const GLenum*, attachments)
GENERATE_FUNCTION_07(void, glInvalidateSubFramebuffer, GLenum, target, GLsizei, numAttachments, const GLenum*, attachments, GLint, x, GLint, y, GLsizei, width, GLsizei, height)
GENERATE_FUNCTION_05(void, glTexStorage2D, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width, GLsizei, height)
GENERATE_FUNCTION_06(void, glTexStorage3D, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth)
GENERATE_FUNCTION_05(void, glGetInternalformativ, GLenum, target, GLenum, internalformat, GLenum, pname, GLsizei, bufSize, GLint*, params)