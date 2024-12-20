// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "gles.h"
// -------------------------------------------------------------------------------------------------------------------------- //
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { return _gles.glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
void glDispatchComputeIndirect(GLintptr indirect) { return _gles.glDispatchComputeIndirect(indirect); };
void glDrawArraysIndirect(GLenum mode, const void* indirect) { return _gles.glDrawArraysIndirect(mode, indirect); }
void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) { return _gles.glDrawElementsIndirect(mode, type, indirect); }
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { return _gles.glFramebufferParameteri(target, pname, param); }
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params) { return _gles.glGetFramebufferParameteriv(target, pname, params); }
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params) { return _gles.glGetProgramInterfaceiv(program, programInterface, pname, params); }
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) { return _gles.glGetProgramResourceIndex(program, programInterface, name); }
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) { return _gles.glGetProgramResourceName(program, programInterface, index, bufSize, length, name); }
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params) { return _gles.glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params); }
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) { return _gles.glGetProgramResourceLocation(program, programInterface, name); }
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { return _gles.glUseProgramStages(pipeline, stages, program); }
void glActiveShaderProgram(GLuint pipeline, GLuint program) { return _gles.glActiveShaderProgram(pipeline, program); }
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar*const* strings) { return _gles.glCreateShaderProgramv(type, count, strings); }
void glBindProgramPipeline(GLuint pipeline) { return _gles.glBindProgramPipeline(pipeline); };
void glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines) { return _gles.glDeleteProgramPipelines(n, pipelines); }
void glGenProgramPipelines(GLsizei n, GLuint* pipelines) { return _gles.glGenProgramPipelines(n, pipelines); }
GLboolean glIsProgramPipeline(GLuint pipeline) { return _gles.glIsProgramPipeline(pipeline); };
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params) { return _gles.glGetProgramPipelineiv(pipeline, pname, params); }
void glProgramUniform1i(GLuint program, GLint location, GLint v0) { return _gles.glProgramUniform1i(program, location, v0); }
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { return _gles.glProgramUniform2i(program, location, v0, v1); }
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { return _gles.glProgramUniform3i(program, location, v0, v1, v2); }
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { return _gles.glProgramUniform4i(program, location, v0, v1, v2, v3); }
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { return _gles.glProgramUniform1ui(program, location, v0); }
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) { return _gles.glProgramUniform2ui(program, location, v0, v1); }
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) { return _gles.glProgramUniform3ui(program, location, v0, v1, v2); }
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { return _gles.glProgramUniform4ui(program, location, v0, v1, v2, v3); }
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { return _gles.glProgramUniform1f(program, location, v0); }
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { return _gles.glProgramUniform2f(program, location, v0, v1); }
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { return _gles.glProgramUniform3f(program, location, v0, v1, v2); }
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { return _gles.glProgramUniform4f(program, location, v0, v1, v2, v3); }
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value) { return _gles.glProgramUniform1iv(program, location, count, value); }
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value) { return _gles.glProgramUniform2iv(program, location, count, value); }
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value) { return _gles.glProgramUniform3iv(program, location, count, value); }
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value) { return _gles.glProgramUniform4iv(program, location, count, value); }
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) { return _gles.glProgramUniform1uiv(program, location, count, value); }
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) { return _gles.glProgramUniform2uiv(program, location, count, value); }
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) { return _gles.glProgramUniform3uiv(program, location, count, value); }
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) { return _gles.glProgramUniform4uiv(program, location, count, value); }
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) { return _gles.glProgramUniform1fv(program, location, count, value); }
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) { return _gles.glProgramUniform2fv(program, location, count, value); }
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) { return _gles.glProgramUniform3fv(program, location, count, value); }
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) { return _gles.glProgramUniform4fv(program, location, count, value); }
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix2fv(program, location, count, transpose, value); }
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix3fv(program, location, count, transpose, value); }
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix4fv(program, location, count, transpose, value); }
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix2x3fv(program, location, count, transpose, value); }
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix3x2fv(program, location, count, transpose, value); }
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix2x4fv(program, location, count, transpose, value); }
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix4x2fv(program, location, count, transpose, value); }
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix3x4fv(program, location, count, transpose, value); }
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { return _gles.glProgramUniformMatrix4x3fv(program, location, count, transpose, value); }
void glValidateProgramPipeline(GLuint pipeline) { return _gles.glValidateProgramPipeline(pipeline); };
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { return _gles.glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); }
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) { return _gles.glBindImageTexture(unit, texture, level, layered, layer, access, format); }
void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data) { return _gles.glGetBooleani_v(target, index, data); }
void glMemoryBarrier(GLbitfield barriers) { return _gles.glMemoryBarrier(barriers); };
void glMemoryBarrierByRegion(GLbitfield barriers) { return _gles.glMemoryBarrierByRegion(barriers); };
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { return _gles.glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val) { return _gles.glGetMultisamplefv(pname, index, val); }
void glSampleMaski(GLuint maskNumber, GLbitfield mask) { return _gles.glSampleMaski(maskNumber, mask); }
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params) { return _gles.glGetTexLevelParameteriv(target, level, pname, params); }
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params) { return _gles.glGetTexLevelParameterfv(target, level, pname, params); }
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { return _gles.glBindVertexBuffer(bindingindex, buffer, offset, stride); }
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { return _gles.glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); }
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { return _gles.glVertexAttribIFormat(attribindex, size, type, relativeoffset); }
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { return _gles.glVertexAttribBinding(attribindex, bindingindex); }
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { return _gles.glVertexBindingDivisor(bindingindex, divisor); }