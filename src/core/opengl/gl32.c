// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "gles.h"
// -------------------------------------------------------------------------------------------------------------------------- //
void glBlendBarrier() { return _gles.glBlendBarrier(); }
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth,  GLsizei srcHeight,  GLsizei srcDepth) { return _gles.glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) { return _gles.glDebugMessageControl(source, type, severity, count, ids, enabled); }
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) { return _gles.glDebugMessageInsert(source, type, id, severity, length, buf); }
void glDebugMessageCallback(GLDEBUGPROC callback, const void* userParam) { return _gles.glDebugMessageCallback(callback, userParam); }
GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) { return _gles.glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog); }
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message) { return _gles.glPushDebugGroup(source, id, length, message); }
void glPopDebugGroup() { return _gles.glPopDebugGroup(); }
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label) { return _gles.glObjectLabel(identifier, name, length, label); }
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label) { return _gles.glGetObjectLabel(identifier, name, bufSize, length, label); }
void glObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label) { return _gles.glObjectPtrLabel(ptr, length, label); }
void glGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label) { return _gles.glGetObjectPtrLabel(ptr, bufSize, length, label); }
void glGetPointerv(GLenum pname, void** params) { return _gles.glGetPointerv(pname, params); }
void glEnablei(GLenum target, GLuint index) { return _gles.glEnablei(target, index); }
void glDisablei(GLenum target, GLuint index) { return _gles.glDisablei(target, index); }
void glBlendEquationi(GLuint buf, GLenum mode) { return _gles.glBlendEquationi(buf, mode); }
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { return _gles.glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
void glBlendFunci(GLuint buf, GLenum src, GLenum dst) { return _gles.glBlendFunci(buf, src, dst); }
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { return _gles.glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { return _gles.glColorMaski(index, r, g, b, a); }
GLboolean glIsEnabledi(GLenum target, GLuint index) { return _gles.glIsEnabledi(target, index); }
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) { return _gles.glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) { return _gles.glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex) { return _gles.glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { return _gles.glFramebufferTexture(target, attachment, texture, level); }
void glPrimitiveBoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) { return _gles.glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW); }
GLenum glGetGraphicsResetStatus() { return _gles.glGetGraphicsResetStatus(); }
void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) { return _gles.glReadnPixels(x, y, width, height, format, type, bufSize, data); }
void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) { return _gles.glGetnUniformfv(program, location, bufSize, params); }
void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params) { return _gles.glGetnUniformiv(program, location, bufSize, params); }
void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params) { return _gles.glGetnUniformuiv(program, location, bufSize, params); }
void glMinSampleShading(GLfloat value) { return _gles.glMinSampleShading(value); }
void glPatchParameteri(GLenum pname, GLint value) { return _gles.glPatchParameteri(pname, value); }
void glTexParameterIiv(GLenum target, GLenum pname, const GLint* params) { return _gles.glTexParameterIiv(target, pname, params); }
void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params) { return _gles.glTexParameterIuiv(target, pname, params); }
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params) { return _gles.glGetTexParameterIiv(target, pname, params); }
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params) { return _gles.glGetTexParameterIuiv(target, pname, params); }
void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param) { return _gles.glSamplerParameterIiv(sampler, pname, param); }
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param) { return _gles.glSamplerParameterIuiv(sampler, pname, param); }
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params) { return _gles.glGetSamplerParameterIiv(sampler, pname, params); }
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params) { return _gles.glGetSamplerParameterIuiv(sampler, pname, params); }
void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { return _gles.glTexBuffer(target, internalformat, buffer); }
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { return _gles.glTexBufferRange(target, internalformat, buffer, offset, size); }
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { return _gles.glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }