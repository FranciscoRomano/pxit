// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "gles.h"
// -------------------------------------------------------------------------------------------------------------------------- //
void glReadBuffer(GLenum src) { return _gles.glReadBuffer(src); }
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) { return _gles.glDrawRangeElements(mode, start, end, count, type, indices); }
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) { return _gles.glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) { return _gles.glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { return _gles.glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) { return _gles.glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) { return _gles.glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
void glGenQueries(GLsizei n, GLuint* ids) { return _gles.glGenQueries(n, ids); }
void glDeleteQueries(GLsizei n, const GLuint* ids) { return _gles.glDeleteQueries(n, ids); }
GLboolean glIsQuery(GLuint id) { return _gles.glIsQuery(id); }
void glBeginQuery(GLenum target, GLuint id) { return _gles.glBeginQuery(target, id); }
void glEndQuery(GLenum target) { return _gles.glEndQuery(target); }
void glGetQueryiv(GLenum target, GLenum pname, GLint* params) { return _gles.glGetQueryiv(target, pname, params); }
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) { return _gles.glGetQueryObjectuiv(id, pname, params); }
GLboolean glUnmapBuffer(GLenum target) { return _gles.glUnmapBuffer(target); }
void glGetBufferPointerv(GLenum target, GLenum pname, void** params) { return _gles.glGetBufferPointerv(target, pname, params); }
void glDrawBuffers(GLsizei n, const GLenum* bufs) { return _gles.glDrawBuffers(n, bufs); }
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix2x3fv(location, count, transpose, value); }
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix3x2fv(location, count, transpose, value); }
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix2x4fv(location, count, transpose, value); }
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix4x2fv(location, count, transpose, value); }
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix3x4fv(location, count, transpose, value); }
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix4x3fv(location, count, transpose, value); }
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { return _gles.glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { return _gles.glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { return _gles.glFramebufferTextureLayer(target, attachment, texture, level, layer); }
void* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { return _gles.glMapBufferRange(target, offset, length, access); }
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { return _gles.glFlushMappedBufferRange(target, offset, length); }
void glBindVertexArray(GLuint array) { return _gles.glBindVertexArray(array); }
void glDeleteVertexArrays(GLsizei n, const GLuint* arrays) { return _gles.glDeleteVertexArrays(n, arrays); }
void glGenVertexArrays(GLsizei n, GLuint* arrays) { return _gles.glGenVertexArrays(n, arrays); }
GLboolean glIsVertexArray(GLuint array) { return _gles.glIsVertexArray(array); }
void glGetIntegeri_v(GLenum target, GLuint index, GLint* data) { return _gles.glGetIntegeri_v(target, index, data); }
void glBeginTransformFeedback(GLenum primitiveMode) { return _gles.glBeginTransformFeedback(primitiveMode); }
void glEndTransformFeedback() { return _gles.glEndTransformFeedback(); }
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { return _gles.glBindBufferRange(target, index, buffer, offset, size); }
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { return _gles.glBindBufferBase(target, index, buffer); }
void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar*const* varyings, GLenum bufferMode) { return _gles.glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) { return _gles.glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) { return _gles.glVertexAttribIPointer(index, size, type, stride, pointer); }
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params) { return _gles.glGetVertexAttribIiv(index, pname, params); }
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params) { return _gles.glGetVertexAttribIuiv(index, pname, params); }
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { return _gles.glVertexAttribI4i(index, x, y, z, w); }
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { return _gles.glVertexAttribI4ui(index, x, y, z, w); }
void glVertexAttribI4iv(GLuint index, const GLint* v) { return _gles.glVertexAttribI4iv(index, v); }
void glVertexAttribI4uiv(GLuint index, const GLuint* v) { return _gles.glVertexAttribI4uiv(index, v); }
void glGetUniformuiv(GLuint program, GLint location, GLuint* params) { return _gles.glGetUniformuiv(program, location, params); }
GLint glGetFragDataLocation(GLuint program, const GLchar* name) { return _gles.glGetFragDataLocation(program, name); }
void glUniform1ui(GLint location, GLuint v0) { return _gles.glUniform1ui(location, v0); }
void glUniform2ui(GLint location, GLuint v0, GLuint v1) { return _gles.glUniform2ui(location, v0, v1); }
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { return _gles.glUniform3ui(location, v0, v1, v2); }
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { return _gles.glUniform4ui(location, v0, v1, v2, v3); }
void glUniform1uiv(GLint location, GLsizei count, const GLuint* value) { return _gles.glUniform1uiv(location, count, value); }
void glUniform2uiv(GLint location, GLsizei count, const GLuint* value) { return _gles.glUniform2uiv(location, count, value); }
void glUniform3uiv(GLint location, GLsizei count, const GLuint* value) { return _gles.glUniform3uiv(location, count, value); }
void glUniform4uiv(GLint location, GLsizei count, const GLuint* value) { return _gles.glUniform4uiv(location, count, value); }
void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) { return _gles.glClearBufferiv(buffer, drawbuffer, value); }
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) { return _gles.glClearBufferuiv(buffer, drawbuffer, value); }
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) { return _gles.glClearBufferfv(buffer, drawbuffer, value); }
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { return _gles.glClearBufferfi(buffer, drawbuffer, depth, stencil); }
const GLubyte* glGetStringi(GLenum name, GLuint index) { return _gles.glGetStringi(name, index); }
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { return _gles.glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar*const* uniformNames, GLuint* uniformIndices) { return _gles.glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params) { return _gles.glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
GLuint glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) { return _gles.glGetUniformBlockIndex(program, uniformBlockName); }
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params) { return _gles.glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) { return _gles.glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { return _gles.glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { return _gles.glDrawArraysInstanced(mode, first, count, instancecount); }
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) { return _gles.glDrawElementsInstanced(mode, count, type, indices, instancecount); }
GLsync glFenceSync(GLenum condition, GLbitfield flags) { return _gles.glFenceSync(condition, flags); }
GLboolean glIsSync(GLsync sync) { return _gles.glIsSync(sync); }
void glDeleteSync(GLsync sync) { return _gles.glDeleteSync(sync); }
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { return _gles.glClientWaitSync(sync, flags, timeout); }
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { return _gles.glWaitSync(sync, flags, timeout); }
void glGetInteger64v(GLenum pname, GLint64* data) { return _gles.glGetInteger64v(pname, data); }
void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values) { return _gles.glGetSynciv(sync, pname, bufSize, length, values); }
void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data) { return _gles.glGetInteger64i_v(target, index, data); }
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params) { return _gles.glGetBufferParameteri64v(target, pname, params); }
void glGenSamplers(GLsizei count, GLuint* samplers) { return _gles.glGenSamplers(count, samplers); }
void glDeleteSamplers(GLsizei count, const GLuint* samplers) { return _gles.glDeleteSamplers(count, samplers); }
GLboolean glIsSampler(GLuint sampler) { return _gles.glIsSampler(sampler); }
void glBindSampler(GLuint unit, GLuint sampler) { return _gles.glBindSampler(unit, sampler); }
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { return _gles.glSamplerParameteri(sampler, pname, param); }
void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param) { return _gles.glSamplerParameteriv(sampler, pname, param); }
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { return _gles.glSamplerParameterf(sampler, pname, param); }
void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param) { return _gles.glSamplerParameterfv(sampler, pname, param); }
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params) { return _gles.glGetSamplerParameteriv(sampler, pname, params); }
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params) { return _gles.glGetSamplerParameterfv(sampler, pname, params); }
void glVertexAttribDivisor(GLuint index, GLuint divisor) { return _gles.glVertexAttribDivisor(index, divisor); }
void glBindTransformFeedback(GLenum target, GLuint id) { return _gles.glBindTransformFeedback(target, id); }
void glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) { return _gles.glDeleteTransformFeedbacks(n, ids); }
void glGenTransformFeedbacks(GLsizei n, GLuint* ids) { return _gles.glGenTransformFeedbacks(n, ids); }
GLboolean glIsTransformFeedback(GLuint id) { return _gles.glIsTransformFeedback(id); }
void glPauseTransformFeedback() { return _gles.glPauseTransformFeedback(); }
void glResumeTransformFeedback() { return _gles.glResumeTransformFeedback(); }
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary) { return _gles.glGetProgramBinary(program, bufSize, length, binaryFormat, binary); }
void glProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length) { return _gles.glProgramBinary(program, binaryFormat, binary, length); }
void glProgramParameteri(GLuint program, GLenum pname, GLint value) { return _gles.glProgramParameteri(program, pname, value); }
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) { return _gles.glInvalidateFramebuffer(target, numAttachments, attachments); }
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) { return _gles.glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); }
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { return _gles.glTexStorage2D(target, levels, internalformat, width, height); }
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { return _gles.glTexStorage3D(target, levels, internalformat, width, height, depth); }
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params) { return _gles.glGetInternalformativ(target, internalformat, pname, bufSize, params); }