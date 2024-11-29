// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOAD_OPTIONAL_SYMBOL(Version, Name)\
Version.Name = loader(#Name);\
if (!Version.Name) { printf("WARNING: failed to load symbol '" #Name "'\n"); }
#define LOAD_REQUIRED_SYMBOL(Version, Name)\
Version.Name = loader(#Name);\
if (!Version.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct ModuleGLES20 GLES20 = { NULL };
struct ModuleGLES30 GLES30 = { NULL };
struct ModuleGLES31 GLES31 = { NULL };
struct ModuleGLES32 GLES32 = { NULL };

bool LoadModuleGLES(void* (*loader)(const char*))
{
    // check GLES version
    LOAD_REQUIRED_SYMBOL(GLES20, glGetString);
    const GLubyte* version = GLES20.glGetString(GL_VERSION);
    if (!version) version = "3.2";

    // load GLES 2.0 symbols
    LOAD_REQUIRED_SYMBOL(GLES20, glActiveTexture);
    LOAD_REQUIRED_SYMBOL(GLES20, glAttachShader);
    LOAD_REQUIRED_SYMBOL(GLES20, glBindAttribLocation);
    LOAD_REQUIRED_SYMBOL(GLES20, glBindBuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glBindFramebuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glBindRenderbuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glBindTexture);
    LOAD_REQUIRED_SYMBOL(GLES20, glBlendColor);
    LOAD_REQUIRED_SYMBOL(GLES20, glBlendEquation);
    LOAD_REQUIRED_SYMBOL(GLES20, glBlendEquationSeparate);
    LOAD_REQUIRED_SYMBOL(GLES20, glBlendFunc);
    LOAD_REQUIRED_SYMBOL(GLES20, glBlendFuncSeparate);
    LOAD_REQUIRED_SYMBOL(GLES20, glBufferData);
    LOAD_REQUIRED_SYMBOL(GLES20, glBufferSubData);
    LOAD_REQUIRED_SYMBOL(GLES20, glCheckFramebufferStatus);
    LOAD_REQUIRED_SYMBOL(GLES20, glClearColor);
    LOAD_REQUIRED_SYMBOL(GLES20, glClearDepthf);
    LOAD_REQUIRED_SYMBOL(GLES20, glClear);
    LOAD_REQUIRED_SYMBOL(GLES20, glClearStencil);
    LOAD_REQUIRED_SYMBOL(GLES20, glColorMask);
    LOAD_REQUIRED_SYMBOL(GLES20, glCompileShader);
    LOAD_REQUIRED_SYMBOL(GLES20, glCompressedTexImage2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glCompressedTexSubImage2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glCopyTexImage2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glCopyTexSubImage2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glCreateProgram);
    LOAD_REQUIRED_SYMBOL(GLES20, glCreateShader);
    LOAD_REQUIRED_SYMBOL(GLES20, glCullFace);
    LOAD_REQUIRED_SYMBOL(GLES20, glDeleteBuffers);
    LOAD_REQUIRED_SYMBOL(GLES20, glDeleteFramebuffers);
    LOAD_REQUIRED_SYMBOL(GLES20, glDeleteProgram);
    LOAD_REQUIRED_SYMBOL(GLES20, glDeleteRenderbuffers);
    LOAD_REQUIRED_SYMBOL(GLES20, glDeleteShader);
    LOAD_REQUIRED_SYMBOL(GLES20, glDeleteTextures);
    LOAD_REQUIRED_SYMBOL(GLES20, glDepthFunc);
    LOAD_REQUIRED_SYMBOL(GLES20, glDepthMask);
    LOAD_REQUIRED_SYMBOL(GLES20, glDepthRangef);
    LOAD_REQUIRED_SYMBOL(GLES20, glDetachShader);
    LOAD_REQUIRED_SYMBOL(GLES20, glDisable);
    LOAD_REQUIRED_SYMBOL(GLES20, glDisableVertexAttribArray);
    LOAD_REQUIRED_SYMBOL(GLES20, glDrawArrays);
    LOAD_REQUIRED_SYMBOL(GLES20, glDrawElements);
    LOAD_REQUIRED_SYMBOL(GLES20, glEnable);
    LOAD_REQUIRED_SYMBOL(GLES20, glEnableVertexAttribArray);
    LOAD_REQUIRED_SYMBOL(GLES20, glFinish);
    LOAD_REQUIRED_SYMBOL(GLES20, glFlush);
    LOAD_REQUIRED_SYMBOL(GLES20, glFramebufferRenderbuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glFramebufferTexture2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glFrontFace);
    LOAD_REQUIRED_SYMBOL(GLES20, glGenBuffers);
    LOAD_REQUIRED_SYMBOL(GLES20, glGenerateMipmap);
    LOAD_REQUIRED_SYMBOL(GLES20, glGenFramebuffers);
    LOAD_REQUIRED_SYMBOL(GLES20, glGenRenderbuffers);
    LOAD_REQUIRED_SYMBOL(GLES20, glGenTextures);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetActiveAttrib);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetActiveUniform);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetAttachedShaders);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetAttribLocation);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetBooleanv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetBufferParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetError);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetFloatv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetFramebufferAttachmentParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetIntegerv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetProgramInfoLog);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetProgramiv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetRenderbufferParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetShaderInfoLog);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetShaderiv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetShaderPrecisionFormat);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetShaderSource);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetString);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetTexParameterfv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetTexParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetUniformfv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetUniformiv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetUniformLocation);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetVertexAttribfv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetVertexAttribiv);
    LOAD_REQUIRED_SYMBOL(GLES20, glGetVertexAttribPointerv);
    LOAD_REQUIRED_SYMBOL(GLES20, glHint);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsBuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsEnabled);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsFramebuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsProgram);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsRenderbuffer);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsShader);
    LOAD_REQUIRED_SYMBOL(GLES20, glIsTexture);
    LOAD_REQUIRED_SYMBOL(GLES20, glLineWidth);
    LOAD_REQUIRED_SYMBOL(GLES20, glLinkProgram);
    LOAD_REQUIRED_SYMBOL(GLES20, glPixelStorei);
    LOAD_REQUIRED_SYMBOL(GLES20, glPolygonOffset);
    LOAD_REQUIRED_SYMBOL(GLES20, glReadPixels);
    LOAD_REQUIRED_SYMBOL(GLES20, glReleaseShaderCompiler);
    LOAD_REQUIRED_SYMBOL(GLES20, glRenderbufferStorage);
    LOAD_REQUIRED_SYMBOL(GLES20, glSampleCoverage);
    LOAD_REQUIRED_SYMBOL(GLES20, glScissor);
    LOAD_REQUIRED_SYMBOL(GLES20, glShaderBinary);
    LOAD_REQUIRED_SYMBOL(GLES20, glShaderSource);
    LOAD_REQUIRED_SYMBOL(GLES20, glStencilFunc);
    LOAD_REQUIRED_SYMBOL(GLES20, glStencilFuncSeparate);
    LOAD_REQUIRED_SYMBOL(GLES20, glStencilMask);
    LOAD_REQUIRED_SYMBOL(GLES20, glStencilMaskSeparate);
    LOAD_REQUIRED_SYMBOL(GLES20, glStencilOp);
    LOAD_REQUIRED_SYMBOL(GLES20, glStencilOpSeparate);
    LOAD_REQUIRED_SYMBOL(GLES20, glTexImage2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glTexParameterf);
    LOAD_REQUIRED_SYMBOL(GLES20, glTexParameterfv);
    LOAD_REQUIRED_SYMBOL(GLES20, glTexParameteri);
    LOAD_REQUIRED_SYMBOL(GLES20, glTexParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES20, glTexSubImage2D);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform1f);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform1fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform1i);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform1iv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform2f);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform2fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform2i);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform2iv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform3f);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform3fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform3i);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform3iv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform4f);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform4fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform4i);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniform4iv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniformMatrix2fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniformMatrix3fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUniformMatrix4fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glUseProgram);
    LOAD_REQUIRED_SYMBOL(GLES20, glValidateProgram);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib1f);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib1fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib2f);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib2fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib3f);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib3fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib4f);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttrib4fv);
    LOAD_REQUIRED_SYMBOL(GLES20, glVertexAttribPointer);
    LOAD_REQUIRED_SYMBOL(GLES20, glViewport);
    if (strcmp(version, "2.0") <= 0)
    {
        printf("WARNING: loaded OpenGL ES 2.0 symbols\n");
        return true;
    }

    // load GLES 3.0 symbols
    LOAD_REQUIRED_SYMBOL(GLES30, glBeginQuery);
    LOAD_REQUIRED_SYMBOL(GLES30, glBeginTransformFeedback);
    LOAD_REQUIRED_SYMBOL(GLES30, glBindBufferBase);
    LOAD_REQUIRED_SYMBOL(GLES30, glBindBufferRange);
    LOAD_REQUIRED_SYMBOL(GLES30, glBindSampler);
    LOAD_REQUIRED_SYMBOL(GLES30, glBindTransformFeedback);
    LOAD_REQUIRED_SYMBOL(GLES30, glBindVertexArray);
    LOAD_REQUIRED_SYMBOL(GLES30, glBlitFramebuffer);
    LOAD_REQUIRED_SYMBOL(GLES30, glClearBufferfi);
    LOAD_REQUIRED_SYMBOL(GLES30, glClearBufferfv);
    LOAD_REQUIRED_SYMBOL(GLES30, glClearBufferiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glClearBufferuiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glClientWaitSync);
    LOAD_REQUIRED_SYMBOL(GLES30, glCompressedTexImage3D);
    LOAD_REQUIRED_SYMBOL(GLES30, glCompressedTexSubImage3D);
    LOAD_REQUIRED_SYMBOL(GLES30, glCopyBufferSubData);
    LOAD_REQUIRED_SYMBOL(GLES30, glCopyTexSubImage3D);
    LOAD_REQUIRED_SYMBOL(GLES30, glDeleteQueries);
    LOAD_REQUIRED_SYMBOL(GLES30, glDeleteSamplers);
    LOAD_REQUIRED_SYMBOL(GLES30, glDeleteSync);
    LOAD_REQUIRED_SYMBOL(GLES30, glDeleteTransformFeedbacks);
    LOAD_REQUIRED_SYMBOL(GLES30, glDeleteVertexArrays);
    LOAD_REQUIRED_SYMBOL(GLES30, glDrawArraysInstanced);
    LOAD_REQUIRED_SYMBOL(GLES30, glDrawBuffers);
    LOAD_REQUIRED_SYMBOL(GLES30, glDrawElementsInstanced);
    LOAD_REQUIRED_SYMBOL(GLES30, glDrawRangeElements);
    LOAD_REQUIRED_SYMBOL(GLES30, glEndQuery);
    LOAD_REQUIRED_SYMBOL(GLES30, glEndTransformFeedback);
    LOAD_REQUIRED_SYMBOL(GLES30, glFenceSync);
    LOAD_REQUIRED_SYMBOL(GLES30, glFlushMappedBufferRange);
    LOAD_REQUIRED_SYMBOL(GLES30, glFramebufferTextureLayer);
    LOAD_REQUIRED_SYMBOL(GLES30, glGenQueries);
    LOAD_REQUIRED_SYMBOL(GLES30, glGenSamplers);
    LOAD_REQUIRED_SYMBOL(GLES30, glGenTransformFeedbacks);
    LOAD_REQUIRED_SYMBOL(GLES30, glGenVertexArrays);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetActiveUniformBlockiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetActiveUniformBlockName);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetActiveUniformsiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetBufferParameteri64v);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetBufferPointerv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetFragDataLocation);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetInteger64i_v);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetInteger64v);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetIntegeri_v);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetInternalformativ);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetProgramBinary);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetQueryiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetQueryObjectuiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetSamplerParameterfv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetSamplerParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetStringi);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetSynciv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetTransformFeedbackVarying);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetUniformBlockIndex);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetUniformIndices);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetUniformuiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetVertexAttribIiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glGetVertexAttribIuiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glInvalidateFramebuffer);
    LOAD_REQUIRED_SYMBOL(GLES30, glInvalidateSubFramebuffer);
    LOAD_REQUIRED_SYMBOL(GLES30, glIsQuery);
    LOAD_REQUIRED_SYMBOL(GLES30, glIsSampler);
    LOAD_REQUIRED_SYMBOL(GLES30, glIsSync);
    LOAD_REQUIRED_SYMBOL(GLES30, glIsTransformFeedback);
    LOAD_REQUIRED_SYMBOL(GLES30, glIsVertexArray);
    LOAD_REQUIRED_SYMBOL(GLES30, glMapBufferRange);
    LOAD_REQUIRED_SYMBOL(GLES30, glPauseTransformFeedback);
    LOAD_REQUIRED_SYMBOL(GLES30, glProgramBinary);
    LOAD_REQUIRED_SYMBOL(GLES30, glProgramParameteri);
    LOAD_REQUIRED_SYMBOL(GLES30, glReadBuffer);
    LOAD_REQUIRED_SYMBOL(GLES30, glRenderbufferStorageMultisample);
    LOAD_REQUIRED_SYMBOL(GLES30, glResumeTransformFeedback);
    LOAD_REQUIRED_SYMBOL(GLES30, glSamplerParameterf);
    LOAD_REQUIRED_SYMBOL(GLES30, glSamplerParameterfv);
    LOAD_REQUIRED_SYMBOL(GLES30, glSamplerParameteri);
    LOAD_REQUIRED_SYMBOL(GLES30, glSamplerParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES30, glTexImage3D);
    LOAD_REQUIRED_SYMBOL(GLES30, glTexStorage2D);
    LOAD_REQUIRED_SYMBOL(GLES30, glTexStorage3D);
    LOAD_REQUIRED_SYMBOL(GLES30, glTexSubImage3D);
    LOAD_REQUIRED_SYMBOL(GLES30, glTransformFeedbackVaryings);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform1ui);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform1uiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform2ui);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform2uiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform3ui);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform3uiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform4ui);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniform4uiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformBlockBinding);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformMatrix2x3fv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformMatrix2x4fv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformMatrix3x2fv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformMatrix3x4fv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformMatrix4x2fv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUniformMatrix4x3fv);
    LOAD_REQUIRED_SYMBOL(GLES30, glUnmapBuffer);
    LOAD_REQUIRED_SYMBOL(GLES30, glVertexAttribDivisor);
    LOAD_REQUIRED_SYMBOL(GLES30, glVertexAttribI4i);
    LOAD_REQUIRED_SYMBOL(GLES30, glVertexAttribI4iv);
    LOAD_REQUIRED_SYMBOL(GLES30, glVertexAttribI4ui);
    LOAD_REQUIRED_SYMBOL(GLES30, glVertexAttribI4uiv);
    LOAD_REQUIRED_SYMBOL(GLES30, glVertexAttribIPointer);
    LOAD_REQUIRED_SYMBOL(GLES30, glWaitSync);
    if (strcmp(version, "3.0") <= 0)
    {
        printf("WARNING: loaded OpenGL ES 3.0 symbols\n");
        return true;
    }

    // load GLES 3.1 symbols
    LOAD_REQUIRED_SYMBOL(GLES31, glActiveShaderProgram);
    LOAD_REQUIRED_SYMBOL(GLES31, glBindImageTexture);
    LOAD_REQUIRED_SYMBOL(GLES31, glBindProgramPipeline);
    LOAD_REQUIRED_SYMBOL(GLES31, glBindVertexBuffer);
    LOAD_REQUIRED_SYMBOL(GLES31, glCreateShaderProgramv);
    LOAD_REQUIRED_SYMBOL(GLES31, glDeleteProgramPipelines);
    LOAD_REQUIRED_SYMBOL(GLES31, glDispatchCompute);
    LOAD_REQUIRED_SYMBOL(GLES31, glDispatchComputeIndirect);
    LOAD_REQUIRED_SYMBOL(GLES31, glDrawArraysIndirect);
    LOAD_REQUIRED_SYMBOL(GLES31, glDrawElementsIndirect);
    LOAD_REQUIRED_SYMBOL(GLES31, glFramebufferParameteri);
    LOAD_REQUIRED_SYMBOL(GLES31, glGenProgramPipelines);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetBooleani_v);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetFramebufferParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetMultisamplefv);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramInterfaceiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramPipelineInfoLog);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramPipelineiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramResourceIndex);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramResourceiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramResourceLocation);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetProgramResourceName);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetTexLevelParameterfv);
    LOAD_REQUIRED_SYMBOL(GLES31, glGetTexLevelParameteriv);
    LOAD_REQUIRED_SYMBOL(GLES31, glIsProgramPipeline);
    LOAD_REQUIRED_SYMBOL(GLES31, glMemoryBarrier);
    LOAD_REQUIRED_SYMBOL(GLES31, glMemoryBarrierByRegion);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform1f);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform1fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform1i);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform1iv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform1ui);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform1uiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform2f);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform2fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform2i);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform2iv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform2ui);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform2uiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform3f);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform3fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform3i);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform3iv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform3ui);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform3uiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform4f);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform4fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform4i);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform4iv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform4ui);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniform4uiv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix2fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix2x3fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix2x4fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix3fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix3x2fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix3x4fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix4fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix4x2fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glProgramUniformMatrix4x3fv);
    LOAD_REQUIRED_SYMBOL(GLES31, glSampleMaski);
    LOAD_REQUIRED_SYMBOL(GLES31, glTexStorage2DMultisample);
    LOAD_REQUIRED_SYMBOL(GLES31, glUseProgramStages);
    LOAD_REQUIRED_SYMBOL(GLES31, glValidateProgramPipeline);
    LOAD_REQUIRED_SYMBOL(GLES31, glVertexAttribBinding);
    LOAD_REQUIRED_SYMBOL(GLES31, glVertexAttribFormat);
    LOAD_REQUIRED_SYMBOL(GLES31, glVertexAttribIFormat);
    LOAD_REQUIRED_SYMBOL(GLES31, glVertexBindingDivisor);
    if (strcmp(version, "3.1") <= 0)
    {
        printf("WARNING: loaded OpenGL ES 3.1 symbols\n");
        return true;
    }

    // load GLES 3.2 symbols
    LOAD_OPTIONAL_SYMBOL(GLES32, glBlendBarrier);
    LOAD_REQUIRED_SYMBOL(GLES32, glBlendEquationi);
    LOAD_REQUIRED_SYMBOL(GLES32, glBlendEquationSeparatei);
    LOAD_REQUIRED_SYMBOL(GLES32, glBlendFunci);
    LOAD_REQUIRED_SYMBOL(GLES32, glBlendFuncSeparatei);
    LOAD_REQUIRED_SYMBOL(GLES32, glColorMaski);
    LOAD_REQUIRED_SYMBOL(GLES32, glCopyImageSubData);
    LOAD_REQUIRED_SYMBOL(GLES32, glDebugMessageCallback);
    LOAD_REQUIRED_SYMBOL(GLES32, glDebugMessageControl);
    LOAD_REQUIRED_SYMBOL(GLES32, glDebugMessageInsert);
    LOAD_REQUIRED_SYMBOL(GLES32, glDisablei);
    LOAD_REQUIRED_SYMBOL(GLES32, glDrawElementsBaseVertex);
    LOAD_REQUIRED_SYMBOL(GLES32, glDrawElementsInstancedBaseVertex);
    LOAD_REQUIRED_SYMBOL(GLES32, glDrawRangeElementsBaseVertex);
    LOAD_REQUIRED_SYMBOL(GLES32, glEnablei);
    LOAD_REQUIRED_SYMBOL(GLES32, glFramebufferTexture);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetDebugMessageLog);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetGraphicsResetStatus);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetnUniformfv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetnUniformiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetnUniformuiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetObjectLabel);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetObjectPtrLabel);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetPointerv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetSamplerParameterIiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetSamplerParameterIuiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetTexParameterIiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glGetTexParameterIuiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glIsEnabledi);
    LOAD_REQUIRED_SYMBOL(GLES32, glMinSampleShading);
    LOAD_REQUIRED_SYMBOL(GLES32, glObjectLabel);
    LOAD_REQUIRED_SYMBOL(GLES32, glObjectPtrLabel);
    LOAD_REQUIRED_SYMBOL(GLES32, glPatchParameteri);
    LOAD_REQUIRED_SYMBOL(GLES32, glPopDebugGroup);
    LOAD_OPTIONAL_SYMBOL(GLES32, glPrimitiveBoundingBox);
    LOAD_REQUIRED_SYMBOL(GLES32, glPushDebugGroup);
    LOAD_REQUIRED_SYMBOL(GLES32, glReadnPixels);
    LOAD_REQUIRED_SYMBOL(GLES32, glSamplerParameterIiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glSamplerParameterIuiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glTexBuffer);
    LOAD_REQUIRED_SYMBOL(GLES32, glTexBufferRange);
    LOAD_REQUIRED_SYMBOL(GLES32, glTexParameterIiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glTexParameterIuiv);
    LOAD_REQUIRED_SYMBOL(GLES32, glTexStorage3DMultisample);
    if (strcmp(version, "3.2") <= 0)
    {
        printf("WARNING: loaded OpenGL ES 3.2 symbols\n");
        return true;
    }

    return true;
}