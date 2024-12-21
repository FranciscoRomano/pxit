// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "gles.h"
// -------------------------------------------------------------------------------------------------------------------------- //
void glActiveTexture(GLenum texture) { return _gles.glActiveTexture(texture); }
void glAttachShader(GLuint program, GLuint shader) { return _gles.glAttachShader(program, shader); }
void glBindAttribLocation(GLuint program, GLuint index, const GLchar* name) { return _gles.glBindAttribLocation(program, index, name); }
void glBindBuffer(GLenum target, GLuint buffer) { return _gles.glBindBuffer(target, buffer); }
void glBindFramebuffer(GLenum target, GLuint framebuffer) { return _gles.glBindFramebuffer(target, framebuffer); }
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) { return _gles.glBindRenderbuffer(target, renderbuffer); }
void glBindTexture(GLenum target, GLuint texture) { return _gles.glBindTexture(target, texture); }
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { return _gles.glBlendColor(red, green, blue, alpha); }
void glBlendEquation(GLenum mode) { return _gles.glBlendEquation(mode); }
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { return _gles.glBlendEquationSeparate(modeRGB, modeAlpha); }
void glBlendFunc(GLenum sfactor, GLenum dfactor) { return _gles.glBlendFunc(sfactor, dfactor); }
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { return _gles.glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) { return _gles.glBufferData(target, size, data, usage); }
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) { return _gles.glBufferSubData(target, offset, size, data); }
GLenum glCheckFramebufferStatus(GLenum target) { return _gles.glCheckFramebufferStatus(target); }
void glClear(GLbitfield mask) { return _gles.glClear(mask); }
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { return _gles.glClearColor(red, green, blue, alpha); }
void glClearDepthf(GLfloat d) { return _gles.glClearDepthf(d); }
void glClearStencil(GLint s) { return _gles.glClearStencil(s); }
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { return _gles.glColorMask(red, green, blue, alpha); }
void glCompileShader(GLuint shader) { return _gles.glCompileShader(shader); }
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) { return _gles.glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) { return _gles.glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { return _gles.glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { return _gles.glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
GLuint glCreateProgram() { return _gles.glCreateProgram(); }
GLuint glCreateShader(GLenum type) { return _gles.glCreateShader(type); }
void glCullFace(GLenum mode) { return _gles.glCullFace(mode); }
void glDeleteBuffers(GLsizei n, const GLuint* buffers) { return _gles.glDeleteBuffers(n, buffers); }
void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) { return _gles.glDeleteFramebuffers(n, framebuffers); }
void glDeleteProgram(GLuint program) { return _gles.glDeleteProgram(program); }
void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) { return _gles.glDeleteRenderbuffers(n, renderbuffers); }
void glDeleteShader(GLuint shader) { return _gles.glDeleteShader(shader); }
void glDeleteTextures(GLsizei n, const GLuint* textures) { return _gles.glDeleteTextures(n, textures); }
void glDepthFunc(GLenum func) { return _gles.glDepthFunc(func); }
void glDepthMask(GLboolean flag) { return _gles.glDepthMask(flag); }
void glDepthRangef(GLfloat n, GLfloat f) { return _gles.glDepthRangef(n, f); }
void glDetachShader(GLuint program, GLuint shader) { return _gles.glDetachShader(program, shader); }
void glDisable(GLenum cap) { return _gles.glDisable(cap); }
void glDisableVertexAttribArray(GLuint index) { return _gles.glDisableVertexAttribArray(index); }
void glDrawArrays(GLenum mode, GLint first, GLsizei count) { return _gles.glDrawArrays(mode, first, count); }
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) { return _gles.glDrawElements(mode, count, type, indices); }
void glEnable(GLenum cap) { return _gles.glEnable(cap); }
void glEnableVertexAttribArray(GLuint index) { return _gles.glEnableVertexAttribArray(index); }
void glFinish() { return _gles.glFinish(); }
void glFlush() { return _gles.glFlush(); }
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { return _gles.glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { return _gles.glFramebufferTexture2D(target, attachment, textarget, texture, level); }
void glFrontFace(GLenum mode) { return _gles.glFrontFace(mode); }
void glGenBuffers(GLsizei n, GLuint* buffers) { return _gles.glGenBuffers(n, buffers); }
void glGenerateMipmap(GLenum target) { return _gles.glGenerateMipmap(target); }
void glGenFramebuffers(GLsizei n, GLuint* framebuffers) { return _gles.glGenFramebuffers(n, framebuffers); }
void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers) { return _gles.glGenRenderbuffers(n, renderbuffers); }
void glGenTextures(GLsizei n, GLuint* textures) { return _gles.glGenTextures(n, textures); }
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) { return _gles.glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) { return _gles.glGetActiveUniform(program, index, bufSize, length, size, type, name); }
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) { return _gles.glGetAttachedShaders(program, maxCount, count, shaders); }
GLint glGetAttribLocation(GLuint program, const GLchar* name) { return _gles.glGetAttribLocation(program, name); }
void glGetBooleanv(GLenum pname, GLboolean* data) { return _gles.glGetBooleanv(pname, data); }
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params) { return _gles.glGetBufferParameteriv(target, pname, params); }
GLenum glGetError() { return _gles.glGetError(); }
void glGetFloatv(GLenum pname, GLfloat* data) { return _gles.glGetFloatv(pname, data); }
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params) { return _gles.glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
void glGetIntegerv(GLenum pname, GLint* data) { return _gles.glGetIntegerv(pname, data); }
void glGetProgramiv(GLuint program, GLenum pname, GLint* params) { return _gles.glGetProgramiv(program, pname, params); }
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { return _gles.glGetProgramInfoLog(program, bufSize, length, infoLog); }
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params) { return _gles.glGetRenderbufferParameteriv(target, pname, params); }
void glGetShaderiv(GLuint shader, GLenum pname, GLint* params) { return _gles.glGetShaderiv(shader, pname, params); }
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { return _gles.glGetShaderInfoLog(shader, bufSize, length, infoLog); }
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) { return _gles.glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) { return _gles.glGetShaderSource(shader, bufSize, length, source); }
const GLubyte* glGetString(GLenum name) { return _gles.glGetString(name); }
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params) { return _gles.glGetTexParameterfv(target, pname, params); }
void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params) { return _gles.glGetTexParameteriv(target, pname, params); }
void glGetUniformfv(GLuint program, GLint location, GLfloat* params) { return _gles.glGetUniformfv(program, location, params); }
void glGetUniformiv(GLuint program, GLint location, GLint* params) { return _gles.glGetUniformiv(program, location, params); }
GLint glGetUniformLocation(GLuint program, const GLchar* name) { return _gles.glGetUniformLocation(program, name); }
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params) { return _gles.glGetVertexAttribfv(index, pname, params); }
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params) { return _gles.glGetVertexAttribiv(index, pname, params); }
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer) { return _gles.glGetVertexAttribPointerv(index, pname, pointer); }
void glHint(GLenum target, GLenum mode) { return _gles.glHint(target, mode); }
GLboolean glIsBuffer(GLuint buffer) { return _gles.glIsBuffer(buffer); }
GLboolean glIsEnabled(GLenum cap) { return _gles.glIsEnabled(cap); }
GLboolean glIsFramebuffer(GLuint framebuffer) { return _gles.glIsFramebuffer(framebuffer); }
GLboolean glIsProgram(GLuint program) { return _gles.glIsProgram(program); }
GLboolean glIsRenderbuffer(GLuint renderbuffer) { return _gles.glIsRenderbuffer(renderbuffer); }
GLboolean glIsShader(GLuint shader) { return _gles.glIsShader(shader); }
GLboolean glIsTexture(GLuint texture) { return _gles.glIsTexture(texture); }
void glLineWidth(GLfloat width) { return _gles.glLineWidth(width); }
void glLinkProgram(GLuint program) { return _gles.glLinkProgram(program); }
void glPixelStorei(GLenum pname, GLint param) { return _gles.glPixelStorei(pname, param); }
void glPolygonOffset(GLfloat factor, GLfloat units) { return _gles.glPolygonOffset(factor, units); }
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) { return _gles.glReadPixels(x, y, width, height, format, type, pixels); }
void glReleaseShaderCompiler() { return _gles.glReleaseShaderCompiler(); }
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { return _gles.glRenderbufferStorage(target, internalformat, width, height); }
void glSampleCoverage(GLfloat value, GLboolean invert) { return _gles.glSampleCoverage(value, invert); }
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { return _gles.glScissor(x, y, width, height); }
void glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length) { return _gles.glShaderBinary(count, shaders, binaryformat, binary, length); }
void glShaderSource(GLuint shader, GLsizei count, const GLchar*const* string, const GLint* length) { return _gles.glShaderSource(shader, count, string, length); }
void glStencilFunc(GLenum func, GLint ref, GLuint mask) { return _gles.glStencilFunc(func, ref, mask); }
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { return _gles.glStencilFuncSeparate(face, func, ref, mask); }
void glStencilMask(GLuint mask) { return _gles.glStencilMask(mask); }
void glStencilMaskSeparate(GLenum face, GLuint mask) { return _gles.glStencilMaskSeparate(face, mask); }
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { return _gles.glStencilOp(fail, zfail, zpass); }
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { return _gles.glStencilOpSeparate(face, sfail, dpfail, dppass); }
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) { return _gles.glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { return _gles.glTexParameterf(target, pname, param); }
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params) { return _gles.glTexParameterfv(target, pname, params); }
void glTexParameteri(GLenum target, GLenum pname, GLint param) { return _gles.glTexParameteri(target, pname, param); }
void glTexParameteriv(GLenum target, GLenum pname, const GLint* params) { return _gles.glTexParameteriv(target, pname, params); }
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) { return _gles.glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
void glUniform1f(GLint location, GLfloat v0) { return _gles.glUniform1f(location, v0); }
void glUniform1fv(GLint location, GLsizei count, const GLfloat* value) { return _gles.glUniform1fv(location, count, value); }
void glUniform1i(GLint location, GLint v0) { return _gles.glUniform1i(location, v0); }
void glUniform1iv(GLint location, GLsizei count, const GLint* value) { return _gles.glUniform1iv(location, count, value); }
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) { return _gles.glUniform2f(location, v0, v1); }
void glUniform2fv(GLint location, GLsizei count, const GLfloat* value) { return _gles.glUniform2fv(location, count, value); }
void glUniform2i(GLint location, GLint v0, GLint v1) { return _gles.glUniform2i(location, v0, v1); }
void glUniform2iv(GLint location, GLsizei count, const GLint* value) { return _gles.glUniform2iv(location, count, value); }
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { return _gles.glUniform3f(location, v0, v1, v2); }
void glUniform3fv(GLint location, GLsizei count, const GLfloat* value) { return _gles.glUniform3fv(location, count, value); }
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { return _gles.glUniform3i(location, v0, v1, v2); }
void glUniform3iv(GLint location, GLsizei count, const GLint* value) { return _gles.glUniform3iv(location, count, value); }
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { return _gles.glUniform4f(location, v0, v1, v2, v3); }
void glUniform4fv(GLint location, GLsizei count, const GLfloat* value) { return _gles.glUniform4fv(location, count, value); }
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { return _gles.glUniform4i(location, v0, v1, v2, v3); }
void glUniform4iv(GLint location, GLsizei count, const GLint* value) { return _gles.glUniform4iv(location, count, value); }
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix2fv(location, count, transpose, value); }
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix3fv(location, count, transpose, value); }
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glUniformMatrix4fv(location, count, transpose, value); }
void glUseProgram(GLuint program) { return _gles.glUseProgram(program); }
void glValidateProgram(GLuint program) { return _gles.glValidateProgram(program); }
void glVertexAttrib1f(GLuint index, GLfloat x) { return _gles.glVertexAttrib1f(index, x); }
void glVertexAttrib1fv(GLuint index, const GLfloat* v) { return _gles.glVertexAttrib1fv(index, v); }
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { return _gles.glVertexAttrib2f(index, x, y); }
void glVertexAttrib2fv(GLuint index, const GLfloat* v) { return _gles.glVertexAttrib2fv(index, v); }
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { return _gles.glVertexAttrib3f(index, x, y, z); }
void glVertexAttrib3fv(GLuint index, const GLfloat* v) { return _gles.glVertexAttrib3fv(index, v); }
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { return _gles.glVertexAttrib4f(index, x, y, z, w); }
void glVertexAttrib4fv(GLuint index, const GLfloat* v) { return _gles.glVertexAttrib4fv(index, v); }
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) { return _gles.glVertexAttribPointer(index, size, type, normalized, stride, pointer); }
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { return _gles.glViewport(x, y, width, height); }