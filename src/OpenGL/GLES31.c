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
#include <GLES31.h>
#if GL_ES_VERSION_3_1

PFN_glDispatchCompute            glDispatchCompute;
PFN_glDispatchComputeIndirect    glDispatchComputeIndirect;
PFN_glDrawArraysIndirect         glDrawArraysIndirect;
PFN_glDrawElementsIndirect       glDrawElementsIndirect;
PFN_glFramebufferParameteri      glFramebufferParameteri;
PFN_glGetFramebufferParameteriv  glGetFramebufferParameteriv;
PFN_glGetProgramInterfaceiv      glGetProgramInterfaceiv;
PFN_glGetProgramResourceIndex    glGetProgramResourceIndex;
PFN_glGetProgramResourceName     glGetProgramResourceName;
PFN_glGetProgramResourceiv       glGetProgramResourceiv;
PFN_glGetProgramResourceLocation glGetProgramResourceLocation;
PFN_glUseProgramStages           glUseProgramStages;
PFN_glActiveShaderProgram        glActiveShaderProgram;
PFN_glCreateShaderProgramv       glCreateShaderProgramv;
PFN_glBindProgramPipeline        glBindProgramPipeline;
PFN_glDeleteProgramPipelines     glDeleteProgramPipelines;
PFN_glGenProgramPipelines        glGenProgramPipelines;
PFN_glIsProgramPipeline          glIsProgramPipeline;
PFN_glGetProgramPipelineiv       glGetProgramPipelineiv;
PFN_glProgramUniform1i           glProgramUniform1i;
PFN_glProgramUniform2i           glProgramUniform2i;
PFN_glProgramUniform3i           glProgramUniform3i;
PFN_glProgramUniform4i           glProgramUniform4i;
PFN_glProgramUniform1ui          glProgramUniform1ui;
PFN_glProgramUniform2ui          glProgramUniform2ui;
PFN_glProgramUniform3ui          glProgramUniform3ui;
PFN_glProgramUniform4ui          glProgramUniform4ui;
PFN_glProgramUniform1f           glProgramUniform1f;
PFN_glProgramUniform2f           glProgramUniform2f;
PFN_glProgramUniform3f           glProgramUniform3f;
PFN_glProgramUniform4f           glProgramUniform4f;
PFN_glProgramUniform1iv          glProgramUniform1iv;
PFN_glProgramUniform2iv          glProgramUniform2iv;
PFN_glProgramUniform3iv          glProgramUniform3iv;
PFN_glProgramUniform4iv          glProgramUniform4iv;
PFN_glProgramUniform1uiv         glProgramUniform1uiv;
PFN_glProgramUniform2uiv         glProgramUniform2uiv;
PFN_glProgramUniform3uiv         glProgramUniform3uiv;
PFN_glProgramUniform4uiv         glProgramUniform4uiv;
PFN_glProgramUniform1fv          glProgramUniform1fv;
PFN_glProgramUniform2fv          glProgramUniform2fv;
PFN_glProgramUniform3fv          glProgramUniform3fv;
PFN_glProgramUniform4fv          glProgramUniform4fv;
PFN_glProgramUniformMatrix2fv    glProgramUniformMatrix2fv;
PFN_glProgramUniformMatrix3fv    glProgramUniformMatrix3fv;
PFN_glProgramUniformMatrix4fv    glProgramUniformMatrix4fv;
PFN_glProgramUniformMatrix2x3fv  glProgramUniformMatrix2x3fv;
PFN_glProgramUniformMatrix3x2fv  glProgramUniformMatrix3x2fv;
PFN_glProgramUniformMatrix2x4fv  glProgramUniformMatrix2x4fv;
PFN_glProgramUniformMatrix4x2fv  glProgramUniformMatrix4x2fv;
PFN_glProgramUniformMatrix3x4fv  glProgramUniformMatrix3x4fv;
PFN_glProgramUniformMatrix4x3fv  glProgramUniformMatrix4x3fv;
PFN_glValidateProgramPipeline    glValidateProgramPipeline;
PFN_glGetProgramPipelineInfoLog  glGetProgramPipelineInfoLog;
PFN_glBindImageTexture           glBindImageTexture;
PFN_glGetBooleani_v              glGetBooleani_v;
PFN_glMemoryBarrier              glMemoryBarrier;
PFN_glMemoryBarrierByRegion      glMemoryBarrierByRegion;
PFN_glTexStorage2DMultisample    glTexStorage2DMultisample;
PFN_glGetMultisamplefv           glGetMultisamplefv;
PFN_glSampleMaski                glSampleMaski;
PFN_glGetTexLevelParameteriv     glGetTexLevelParameteriv;
PFN_glGetTexLevelParameterfv     glGetTexLevelParameterfv;
PFN_glBindVertexBuffer           glBindVertexBuffer;
PFN_glVertexAttribFormat         glVertexAttribFormat;
PFN_glVertexAttribIFormat        glVertexAttribIFormat;
PFN_glVertexAttribBinding        glVertexAttribBinding;
PFN_glVertexBindingDivisor       glVertexBindingDivisor;

int LoadOpenGLES31(void* (*pfnLoadProc)(const char* name))
{
    if (!LoadOpenGLES30(pfnLoadProc)) return 0;

    #define LOAD_OPENGL_PROCEDURE(name)\
    name = (PFN_##name)pfnLoadProc(#name); if (!name) return 0;
    LOAD_OPENGL_PROCEDURE(glDispatchCompute);
    LOAD_OPENGL_PROCEDURE(glDispatchComputeIndirect);
    LOAD_OPENGL_PROCEDURE(glDrawArraysIndirect);
    LOAD_OPENGL_PROCEDURE(glDrawElementsIndirect);
    LOAD_OPENGL_PROCEDURE(glFramebufferParameteri);
    LOAD_OPENGL_PROCEDURE(glGetFramebufferParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetProgramInterfaceiv);
    LOAD_OPENGL_PROCEDURE(glGetProgramResourceIndex);
    LOAD_OPENGL_PROCEDURE(glGetProgramResourceName);
    LOAD_OPENGL_PROCEDURE(glGetProgramResourceiv);
    LOAD_OPENGL_PROCEDURE(glGetProgramResourceLocation);
    LOAD_OPENGL_PROCEDURE(glUseProgramStages);
    LOAD_OPENGL_PROCEDURE(glActiveShaderProgram);
    LOAD_OPENGL_PROCEDURE(glCreateShaderProgramv);
    LOAD_OPENGL_PROCEDURE(glBindProgramPipeline);
    LOAD_OPENGL_PROCEDURE(glDeleteProgramPipelines);
    LOAD_OPENGL_PROCEDURE(glGenProgramPipelines);
    LOAD_OPENGL_PROCEDURE(glIsProgramPipeline);
    LOAD_OPENGL_PROCEDURE(glGetProgramPipelineiv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform1i);
    LOAD_OPENGL_PROCEDURE(glProgramUniform2i);
    LOAD_OPENGL_PROCEDURE(glProgramUniform3i);
    LOAD_OPENGL_PROCEDURE(glProgramUniform4i);
    LOAD_OPENGL_PROCEDURE(glProgramUniform1ui);
    LOAD_OPENGL_PROCEDURE(glProgramUniform2ui);
    LOAD_OPENGL_PROCEDURE(glProgramUniform3ui);
    LOAD_OPENGL_PROCEDURE(glProgramUniform4ui);
    LOAD_OPENGL_PROCEDURE(glProgramUniform1f);
    LOAD_OPENGL_PROCEDURE(glProgramUniform2f);
    LOAD_OPENGL_PROCEDURE(glProgramUniform3f);
    LOAD_OPENGL_PROCEDURE(glProgramUniform4f);
    LOAD_OPENGL_PROCEDURE(glProgramUniform1iv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform2iv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform3iv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform4iv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform1uiv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform2uiv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform3uiv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform4uiv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform1fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform2fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform3fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniform4fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix2fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix3fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix4fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix2x3fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix3x2fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix2x4fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix4x2fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix3x4fv);
    LOAD_OPENGL_PROCEDURE(glProgramUniformMatrix4x3fv);
    LOAD_OPENGL_PROCEDURE(glValidateProgramPipeline);
    LOAD_OPENGL_PROCEDURE(glGetProgramPipelineInfoLog);
    LOAD_OPENGL_PROCEDURE(glBindImageTexture);
    LOAD_OPENGL_PROCEDURE(glGetBooleani_v);
    LOAD_OPENGL_PROCEDURE(glMemoryBarrier);
    LOAD_OPENGL_PROCEDURE(glMemoryBarrierByRegion);
    LOAD_OPENGL_PROCEDURE(glTexStorage2DMultisample);
    LOAD_OPENGL_PROCEDURE(glGetMultisamplefv);
    LOAD_OPENGL_PROCEDURE(glSampleMaski);
    LOAD_OPENGL_PROCEDURE(glGetTexLevelParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetTexLevelParameterfv);
    LOAD_OPENGL_PROCEDURE(glBindVertexBuffer);
    LOAD_OPENGL_PROCEDURE(glVertexAttribFormat);
    LOAD_OPENGL_PROCEDURE(glVertexAttribIFormat);
    LOAD_OPENGL_PROCEDURE(glVertexAttribBinding);
    LOAD_OPENGL_PROCEDURE(glVertexBindingDivisor);
    #undef LOAD_OPENGL_PROCEDURE
    return 1;
}

#endif//GL_ES_VERSION_3_1
// ---------------------------------------------------------------------------------------------- //