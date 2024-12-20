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
GENERATE_FUNCTION_03(void, glDispatchCompute, GLuint, num_groups_x, GLuint, num_groups_y, GLuint, num_groups_z)
GENERATE_FUNCTION_01(void, glDispatchComputeIndirect, GLintptr, indirect);
GENERATE_FUNCTION_02(void, glDrawArraysIndirect, GLenum, mode, const void*, indirect)
GENERATE_FUNCTION_03(void, glDrawElementsIndirect, GLenum, mode, GLenum, type, const void*, indirect)
GENERATE_FUNCTION_03(void, glFramebufferParameteri, GLenum, target, GLenum, pname, GLint, param)
GENERATE_FUNCTION_03(void, glGetFramebufferParameteriv, GLenum, target, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_04(void, glGetProgramInterfaceiv, GLuint, program, GLenum, programInterface, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_03(GLuint, glGetProgramResourceIndex, GLuint, program, GLenum, programInterface, const GLchar*, name)
GENERATE_FUNCTION_06(void, glGetProgramResourceName, GLuint, program, GLenum, programInterface, GLuint, index, GLsizei, bufSize, GLsizei*, length, GLchar*, name)
GENERATE_FUNCTION_08(void, glGetProgramResourceiv, GLuint, program, GLenum, programInterface, GLuint, index, GLsizei, propCount, const GLenum*, props, GLsizei, bufSize, GLsizei*, length, GLint*, params)
GENERATE_FUNCTION_03(GLint, glGetProgramResourceLocation, GLuint, program, GLenum, programInterface, const GLchar*, name)
GENERATE_FUNCTION_03(void, glUseProgramStages, GLuint, pipeline, GLbitfield, stages, GLuint, program)
GENERATE_FUNCTION_02(void, glActiveShaderProgram, GLuint, pipeline, GLuint, program)
GENERATE_FUNCTION_03(GLuint, glCreateShaderProgramv, GLenum, type, GLsizei, count, const GLchar*const*, strings)
GENERATE_FUNCTION_01(void, glBindProgramPipeline, GLuint, pipeline);
GENERATE_FUNCTION_02(void, glDeleteProgramPipelines, GLsizei, n, const GLuint*, pipelines)
GENERATE_FUNCTION_02(void, glGenProgramPipelines, GLsizei, n, GLuint*, pipelines)
GENERATE_FUNCTION_01(GLboolean, glIsProgramPipeline, GLuint, pipeline);
GENERATE_FUNCTION_03(void, glGetProgramPipelineiv, GLuint, pipeline, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_03(void, glProgramUniform1i, GLuint, program, GLint, location, GLint, v0)
GENERATE_FUNCTION_04(void, glProgramUniform2i, GLuint, program, GLint, location, GLint, v0, GLint, v1)
GENERATE_FUNCTION_05(void, glProgramUniform3i, GLuint, program, GLint, location, GLint, v0, GLint, v1, GLint, v2)
GENERATE_FUNCTION_06(void, glProgramUniform4i, GLuint, program, GLint, location, GLint, v0, GLint, v1, GLint, v2, GLint, v3)
GENERATE_FUNCTION_03(void, glProgramUniform1ui, GLuint, program, GLint, location, GLuint, v0)
GENERATE_FUNCTION_04(void, glProgramUniform2ui, GLuint, program, GLint, location, GLuint, v0, GLuint, v1)
GENERATE_FUNCTION_05(void, glProgramUniform3ui, GLuint, program, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2)
GENERATE_FUNCTION_06(void, glProgramUniform4ui, GLuint, program, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2, GLuint, v3)
GENERATE_FUNCTION_03(void, glProgramUniform1f, GLuint, program, GLint, location, GLfloat, v0)
GENERATE_FUNCTION_04(void, glProgramUniform2f, GLuint, program, GLint, location, GLfloat, v0, GLfloat, v1)
GENERATE_FUNCTION_05(void, glProgramUniform3f, GLuint, program, GLint, location, GLfloat, v0, GLfloat, v1, GLfloat, v2)
GENERATE_FUNCTION_06(void, glProgramUniform4f, GLuint, program, GLint, location, GLfloat, v0, GLfloat, v1, GLfloat, v2, GLfloat, v3)
GENERATE_FUNCTION_04(void, glProgramUniform1iv, GLuint, program, GLint, location, GLsizei, count, const GLint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform2iv, GLuint, program, GLint, location, GLsizei, count, const GLint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform3iv, GLuint, program, GLint, location, GLsizei, count, const GLint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform4iv, GLuint, program, GLint, location, GLsizei, count, const GLint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform1uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform2uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform3uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform4uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint*, value)
GENERATE_FUNCTION_04(void, glProgramUniform1fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glProgramUniform2fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glProgramUniform3fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat*, value)
GENERATE_FUNCTION_04(void, glProgramUniform4fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix2fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix3fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix4fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix2x3fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix3x2fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix2x4fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix4x2fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix3x4fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_05(void, glProgramUniformMatrix4x3fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat*, value)
GENERATE_FUNCTION_01(void, glValidateProgramPipeline, GLuint, pipeline);
GENERATE_FUNCTION_04(void, glGetProgramPipelineInfoLog, GLuint, pipeline, GLsizei, bufSize, GLsizei*, length, GLchar*, infoLog)
GENERATE_FUNCTION_07(void, glBindImageTexture, GLuint, unit, GLuint, texture, GLint, level, GLboolean, layered, GLint, layer, GLenum, access, GLenum, format)
GENERATE_FUNCTION_03(void, glGetBooleani_v, GLenum, target, GLuint, index, GLboolean*, data)
GENERATE_FUNCTION_01(void, glMemoryBarrier, GLbitfield, barriers);
GENERATE_FUNCTION_01(void, glMemoryBarrierByRegion, GLbitfield, barriers);
GENERATE_FUNCTION_06(void, glTexStorage2DMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLboolean, fixedsamplelocations)
GENERATE_FUNCTION_03(void, glGetMultisamplefv, GLenum, pname, GLuint, index, GLfloat*, val)
GENERATE_FUNCTION_02(void, glSampleMaski, GLuint, maskNumber, GLbitfield, mask)
GENERATE_FUNCTION_04(void, glGetTexLevelParameteriv, GLenum, target, GLint, level, GLenum, pname, GLint*, params)
GENERATE_FUNCTION_04(void, glGetTexLevelParameterfv, GLenum, target, GLint, level, GLenum, pname, GLfloat*, params)
GENERATE_FUNCTION_04(void, glBindVertexBuffer, GLuint, bindingindex, GLuint, buffer, GLintptr, offset, GLsizei, stride)
GENERATE_FUNCTION_05(void, glVertexAttribFormat, GLuint, attribindex, GLint, size, GLenum, type, GLboolean, normalized, GLuint, relativeoffset)
GENERATE_FUNCTION_04(void, glVertexAttribIFormat, GLuint, attribindex, GLint, size, GLenum, type, GLuint, relativeoffset)
GENERATE_FUNCTION_02(void, glVertexAttribBinding, GLuint, attribindex, GLuint, bindingindex)
GENERATE_FUNCTION_02(void, glVertexBindingDivisor, GLuint, bindingindex, GLuint, divisor)