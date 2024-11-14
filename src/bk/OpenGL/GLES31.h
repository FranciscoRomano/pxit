// ---------------------------------------------------------------------------------------------- //
// The MIT License (MIT)
// 
// Copyright (c) 2024 Francisco Romano
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ---------------------------------------------------------------------------------------------- //
#ifndef __GLES31_h__
#define __GLES31_h__
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus
// ---------------------------------------------------------------------------------------------- //
#include "GLES30.h"
#include <GLES3/gl31.h>
#if GL_ES_VERSION_3_1

extern PFN_glDispatchCompute            glDispatchCompute;
extern PFN_glDispatchComputeIndirect    glDispatchComputeIndirect;
extern PFN_glDrawArraysIndirect         glDrawArraysIndirect;
extern PFN_glDrawElementsIndirect       glDrawElementsIndirect;
extern PFN_glFramebufferParameteri      glFramebufferParameteri;
extern PFN_glGetFramebufferParameteriv  glGetFramebufferParameteriv;
extern PFN_glGetProgramInterfaceiv      glGetProgramInterfaceiv;
extern PFN_glGetProgramResourceIndex    glGetProgramResourceIndex;
extern PFN_glGetProgramResourceName     glGetProgramResourceName;
extern PFN_glGetProgramResourceiv       glGetProgramResourceiv;
extern PFN_glGetProgramResourceLocation glGetProgramResourceLocation;
extern PFN_glUseProgramStages           glUseProgramStages;
extern PFN_glActiveShaderProgram        glActiveShaderProgram;
extern PFN_glCreateShaderProgramv       glCreateShaderProgramv;
extern PFN_glBindProgramPipeline        glBindProgramPipeline;
extern PFN_glDeleteProgramPipelines     glDeleteProgramPipelines;
extern PFN_glGenProgramPipelines        glGenProgramPipelines;
extern PFN_glIsProgramPipeline          glIsProgramPipeline;
extern PFN_glGetProgramPipelineiv       glGetProgramPipelineiv;
extern PFN_glProgramUniform1i           glProgramUniform1i;
extern PFN_glProgramUniform2i           glProgramUniform2i;
extern PFN_glProgramUniform3i           glProgramUniform3i;
extern PFN_glProgramUniform4i           glProgramUniform4i;
extern PFN_glProgramUniform1ui          glProgramUniform1ui;
extern PFN_glProgramUniform2ui          glProgramUniform2ui;
extern PFN_glProgramUniform3ui          glProgramUniform3ui;
extern PFN_glProgramUniform4ui          glProgramUniform4ui;
extern PFN_glProgramUniform1f           glProgramUniform1f;
extern PFN_glProgramUniform2f           glProgramUniform2f;
extern PFN_glProgramUniform3f           glProgramUniform3f;
extern PFN_glProgramUniform4f           glProgramUniform4f;
extern PFN_glProgramUniform1iv          glProgramUniform1iv;
extern PFN_glProgramUniform2iv          glProgramUniform2iv;
extern PFN_glProgramUniform3iv          glProgramUniform3iv;
extern PFN_glProgramUniform4iv          glProgramUniform4iv;
extern PFN_glProgramUniform1uiv         glProgramUniform1uiv;
extern PFN_glProgramUniform2uiv         glProgramUniform2uiv;
extern PFN_glProgramUniform3uiv         glProgramUniform3uiv;
extern PFN_glProgramUniform4uiv         glProgramUniform4uiv;
extern PFN_glProgramUniform1fv          glProgramUniform1fv;
extern PFN_glProgramUniform2fv          glProgramUniform2fv;
extern PFN_glProgramUniform3fv          glProgramUniform3fv;
extern PFN_glProgramUniform4fv          glProgramUniform4fv;
extern PFN_glProgramUniformMatrix2fv    glProgramUniformMatrix2fv;
extern PFN_glProgramUniformMatrix3fv    glProgramUniformMatrix3fv;
extern PFN_glProgramUniformMatrix4fv    glProgramUniformMatrix4fv;
extern PFN_glProgramUniformMatrix2x3fv  glProgramUniformMatrix2x3fv;
extern PFN_glProgramUniformMatrix3x2fv  glProgramUniformMatrix3x2fv;
extern PFN_glProgramUniformMatrix2x4fv  glProgramUniformMatrix2x4fv;
extern PFN_glProgramUniformMatrix4x2fv  glProgramUniformMatrix4x2fv;
extern PFN_glProgramUniformMatrix3x4fv  glProgramUniformMatrix3x4fv;
extern PFN_glProgramUniformMatrix4x3fv  glProgramUniformMatrix4x3fv;
extern PFN_glValidateProgramPipeline    glValidateProgramPipeline;
extern PFN_glGetProgramPipelineInfoLog  glGetProgramPipelineInfoLog;
extern PFN_glBindImageTexture           glBindImageTexture;
extern PFN_glGetBooleani_v              glGetBooleani_v;
extern PFN_glMemoryBarrier              glMemoryBarrier;
extern PFN_glMemoryBarrierByRegion      glMemoryBarrierByRegion;
extern PFN_glTexStorage2DMultisample    glTexStorage2DMultisample;
extern PFN_glGetMultisamplefv           glGetMultisamplefv;
extern PFN_glSampleMaski                glSampleMaski;
extern PFN_glGetTexLevelParameteriv     glGetTexLevelParameteriv;
extern PFN_glGetTexLevelParameterfv     glGetTexLevelParameterfv;
extern PFN_glBindVertexBuffer           glBindVertexBuffer;
extern PFN_glVertexAttribFormat         glVertexAttribFormat;
extern PFN_glVertexAttribIFormat        glVertexAttribIFormat;
extern PFN_glVertexAttribBinding        glVertexAttribBinding;
extern PFN_glVertexBindingDivisor       glVertexBindingDivisor;

/// @brief Returns "1" if all OpenGL ES 3.1 procedures were loaded successfully.
/// @param pfnGetProc A function pointer to a OpenGL procedure loader.
int LoadOpenGLES31(void* (*pfnLoadProc)(const char* name));

#endif//GL_ES_VERSION_3_1
// ---------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif//__cplusplus
#endif//__GLES31_h__
// ---------------------------------------------------------------------------------------------- //