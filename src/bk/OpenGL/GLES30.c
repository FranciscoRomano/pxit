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
#include <GLES30.h>
#if GL_ES_VERSION_3_0

PFN_glReadBuffer                     glReadBuffer;
PFN_glDrawRangeElements              glDrawRangeElements;
PFN_glTexImage3D                     glTexImage3D;
PFN_glTexSubImage3D                  glTexSubImage3D;
PFN_glCopyTexSubImage3D              glCopyTexSubImage3D;
PFN_glCompressedTexImage3D           glCompressedTexImage3D;
PFN_glCompressedTexSubImage3D        glCompressedTexSubImage3D;
PFN_glGenQueries                     glGenQueries;
PFN_glDeleteQueries                  glDeleteQueries;
PFN_glIsQuery                        glIsQuery;
PFN_glBeginQuery                     glBeginQuery;
PFN_glEndQuery                       glEndQuery;
PFN_glGetQueryiv                     glGetQueryiv;
PFN_glGetQueryObjectuiv              glGetQueryObjectuiv;
PFN_glUnmapBuffer                    glUnmapBuffer;
PFN_glGetBufferPointerv              glGetBufferPointerv;
PFN_glDrawBuffers                    glDrawBuffers;
PFN_glUniformMatrix2x3fv             glUniformMatrix2x3fv;
PFN_glUniformMatrix3x2fv             glUniformMatrix3x2fv;
PFN_glUniformMatrix2x4fv             glUniformMatrix2x4fv;
PFN_glUniformMatrix4x2fv             glUniformMatrix4x2fv;
PFN_glUniformMatrix3x4fv             glUniformMatrix3x4fv;
PFN_glUniformMatrix4x3fv             glUniformMatrix4x3fv;
PFN_glBlitFramebuffer                glBlitFramebuffer;
PFN_glRenderbufferStorageMultisample glRenderbufferStorageMultisample;
PFN_glFramebufferTextureLayer        glFramebufferTextureLayer;
PFN_glMapBufferRange                 glMapBufferRange;
PFN_glFlushMappedBufferRange         glFlushMappedBufferRange;
PFN_glBindVertexArray                glBindVertexArray;
PFN_glDeleteVertexArrays             glDeleteVertexArrays;
PFN_glGenVertexArrays                glGenVertexArrays;
PFN_glIsVertexArray                  glIsVertexArray;
PFN_glGetIntegeri_v                  glGetIntegeri_v;
PFN_glBeginTransformFeedback         glBeginTransformFeedback;
PFN_glEndTransformFeedback           glEndTransformFeedback;
PFN_glBindBufferRange                glBindBufferRange;
PFN_glBindBufferBase                 glBindBufferBase;
PFN_glTransformFeedbackVaryings      glTransformFeedbackVaryings;
PFN_glGetTransformFeedbackVarying    glGetTransformFeedbackVarying;
PFN_glVertexAttribIPointer           glVertexAttribIPointer;
PFN_glGetVertexAttribIiv             glGetVertexAttribIiv;
PFN_glGetVertexAttribIuiv            glGetVertexAttribIuiv;
PFN_glVertexAttribI4i                glVertexAttribI4i;
PFN_glVertexAttribI4ui               glVertexAttribI4ui;
PFN_glVertexAttribI4iv               glVertexAttribI4iv;
PFN_glVertexAttribI4uiv              glVertexAttribI4uiv;
PFN_glGetUniformuiv                  glGetUniformuiv;
PFN_glGetFragDataLocation            glGetFragDataLocation;
PFN_glUniform1ui                     glUniform1ui;
PFN_glUniform2ui                     glUniform2ui;
PFN_glUniform3ui                     glUniform3ui;
PFN_glUniform4ui                     glUniform4ui;
PFN_glUniform1uiv                    glUniform1uiv;
PFN_glUniform2uiv                    glUniform2uiv;
PFN_glUniform3uiv                    glUniform3uiv;
PFN_glUniform4uiv                    glUniform4uiv;
PFN_glClearBufferiv                  glClearBufferiv;
PFN_glClearBufferuiv                 glClearBufferuiv;
PFN_glClearBufferfv                  glClearBufferfv;
PFN_glClearBufferfi                  glClearBufferfi;
PFN_glGetStringi                     glGetStringi;
PFN_glCopyBufferSubData              glCopyBufferSubData;
PFN_glGetUniformIndices              glGetUniformIndices;
PFN_glGetActiveUniformsiv            glGetActiveUniformsiv;
PFN_glGetUniformBlockIndex           glGetUniformBlockIndex;
PFN_glGetActiveUniformBlockiv        glGetActiveUniformBlockiv;
PFN_glGetActiveUniformBlockName      glGetActiveUniformBlockName;
PFN_glUniformBlockBinding            glUniformBlockBinding;
PFN_glDrawArraysInstanced            glDrawArraysInstanced;
PFN_glDrawElementsInstanced          glDrawElementsInstanced;
PFN_glFenceSync                      glFenceSync;
PFN_glIsSync                         glIsSync;
PFN_glDeleteSync                     glDeleteSync;
PFN_glClientWaitSync                 glClientWaitSync;
PFN_glWaitSync                       glWaitSync;
PFN_glGetInteger64v                  glGetInteger64v;
PFN_glGetSynciv                      glGetSynciv;
PFN_glGetInteger64i_v                glGetInteger64i_v;
PFN_glGetBufferParameteri64v         glGetBufferParameteri64v;
PFN_glGenSamplers                    glGenSamplers;
PFN_glDeleteSamplers                 glDeleteSamplers;
PFN_glIsSampler                      glIsSampler;
PFN_glBindSampler                    glBindSampler;
PFN_glSamplerParameteri              glSamplerParameteri;
PFN_glSamplerParameteriv             glSamplerParameteriv;
PFN_glSamplerParameterf              glSamplerParameterf;
PFN_glSamplerParameterfv             glSamplerParameterfv;
PFN_glGetSamplerParameteriv          glGetSamplerParameteriv;
PFN_glGetSamplerParameterfv          glGetSamplerParameterfv;
PFN_glVertexAttribDivisor            glVertexAttribDivisor;
PFN_glBindTransformFeedback          glBindTransformFeedback;
PFN_glDeleteTransformFeedbacks       glDeleteTransformFeedbacks;
PFN_glGenTransformFeedbacks          glGenTransformFeedbacks;
PFN_glIsTransformFeedback            glIsTransformFeedback;
PFN_glPauseTransformFeedback         glPauseTransformFeedback;
PFN_glResumeTransformFeedback        glResumeTransformFeedback;
PFN_glGetProgramBinary               glGetProgramBinary;
PFN_glProgramBinary                  glProgramBinary;
PFN_glProgramParameteri              glProgramParameteri;
PFN_glInvalidateFramebuffer          glInvalidateFramebuffer;
PFN_glInvalidateSubFramebuffer       glInvalidateSubFramebuffer;
PFN_glTexStorage2D                   glTexStorage2D;
PFN_glTexStorage3D                   glTexStorage3D;
PFN_glGetInternalformativ            glGetInternalformativ;

int LoadOpenGLES30(void* (*pfnLoadProc)(const char* name))
{
    if (!LoadOpenGLES20(pfnLoadProc)) return 0;

    #define LOAD_OPENGL_PROCEDURE(name)\
    name = (PFN_##name)pfnLoadProc(#name); if (!name) return 0;
    LOAD_OPENGL_PROCEDURE(glReadBuffer);
    LOAD_OPENGL_PROCEDURE(glDrawRangeElements);
    LOAD_OPENGL_PROCEDURE(glTexImage3D);
    LOAD_OPENGL_PROCEDURE(glTexSubImage3D);
    LOAD_OPENGL_PROCEDURE(glCopyTexSubImage3D);
    LOAD_OPENGL_PROCEDURE(glCompressedTexImage3D);
    LOAD_OPENGL_PROCEDURE(glCompressedTexSubImage3D);
    LOAD_OPENGL_PROCEDURE(glGenQueries);
    LOAD_OPENGL_PROCEDURE(glDeleteQueries);
    LOAD_OPENGL_PROCEDURE(glIsQuery);
    LOAD_OPENGL_PROCEDURE(glBeginQuery);
    LOAD_OPENGL_PROCEDURE(glEndQuery);
    LOAD_OPENGL_PROCEDURE(glGetQueryiv);
    LOAD_OPENGL_PROCEDURE(glGetQueryObjectuiv);
    LOAD_OPENGL_PROCEDURE(glUnmapBuffer);
    LOAD_OPENGL_PROCEDURE(glGetBufferPointerv);
    LOAD_OPENGL_PROCEDURE(glDrawBuffers);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix2x3fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix3x2fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix2x4fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix4x2fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix3x4fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix4x3fv);
    LOAD_OPENGL_PROCEDURE(glBlitFramebuffer);
    LOAD_OPENGL_PROCEDURE(glRenderbufferStorageMultisample);
    LOAD_OPENGL_PROCEDURE(glFramebufferTextureLayer);
    LOAD_OPENGL_PROCEDURE(glMapBufferRange);
    LOAD_OPENGL_PROCEDURE(glFlushMappedBufferRange);
    LOAD_OPENGL_PROCEDURE(glBindVertexArray);
    LOAD_OPENGL_PROCEDURE(glDeleteVertexArrays);
    LOAD_OPENGL_PROCEDURE(glGenVertexArrays);
    LOAD_OPENGL_PROCEDURE(glIsVertexArray);
    LOAD_OPENGL_PROCEDURE(glGetIntegeri_v);
    LOAD_OPENGL_PROCEDURE(glBeginTransformFeedback);
    LOAD_OPENGL_PROCEDURE(glEndTransformFeedback);
    LOAD_OPENGL_PROCEDURE(glBindBufferRange);
    LOAD_OPENGL_PROCEDURE(glBindBufferBase);
    LOAD_OPENGL_PROCEDURE(glTransformFeedbackVaryings);
    LOAD_OPENGL_PROCEDURE(glGetTransformFeedbackVarying);
    LOAD_OPENGL_PROCEDURE(glVertexAttribIPointer);
    LOAD_OPENGL_PROCEDURE(glGetVertexAttribIiv);
    LOAD_OPENGL_PROCEDURE(glGetVertexAttribIuiv);
    LOAD_OPENGL_PROCEDURE(glVertexAttribI4i);
    LOAD_OPENGL_PROCEDURE(glVertexAttribI4ui);
    LOAD_OPENGL_PROCEDURE(glVertexAttribI4iv);
    LOAD_OPENGL_PROCEDURE(glVertexAttribI4uiv);
    LOAD_OPENGL_PROCEDURE(glGetUniformuiv);
    LOAD_OPENGL_PROCEDURE(glGetFragDataLocation);
    LOAD_OPENGL_PROCEDURE(glUniform1ui);
    LOAD_OPENGL_PROCEDURE(glUniform2ui);
    LOAD_OPENGL_PROCEDURE(glUniform3ui);
    LOAD_OPENGL_PROCEDURE(glUniform4ui);
    LOAD_OPENGL_PROCEDURE(glUniform1uiv);
    LOAD_OPENGL_PROCEDURE(glUniform2uiv);
    LOAD_OPENGL_PROCEDURE(glUniform3uiv);
    LOAD_OPENGL_PROCEDURE(glUniform4uiv);
    LOAD_OPENGL_PROCEDURE(glClearBufferiv);
    LOAD_OPENGL_PROCEDURE(glClearBufferuiv);
    LOAD_OPENGL_PROCEDURE(glClearBufferfv);
    LOAD_OPENGL_PROCEDURE(glClearBufferfi);
    LOAD_OPENGL_PROCEDURE(glGetStringi);
    LOAD_OPENGL_PROCEDURE(glCopyBufferSubData);
    LOAD_OPENGL_PROCEDURE(glGetUniformIndices);
    LOAD_OPENGL_PROCEDURE(glGetActiveUniformsiv);
    LOAD_OPENGL_PROCEDURE(glGetUniformBlockIndex);
    LOAD_OPENGL_PROCEDURE(glGetActiveUniformBlockiv);
    LOAD_OPENGL_PROCEDURE(glGetActiveUniformBlockName);
    LOAD_OPENGL_PROCEDURE(glUniformBlockBinding);
    LOAD_OPENGL_PROCEDURE(glDrawArraysInstanced);
    LOAD_OPENGL_PROCEDURE(glDrawElementsInstanced);
    LOAD_OPENGL_PROCEDURE(glFenceSync);
    LOAD_OPENGL_PROCEDURE(glIsSync);
    LOAD_OPENGL_PROCEDURE(glDeleteSync);
    LOAD_OPENGL_PROCEDURE(glClientWaitSync);
    LOAD_OPENGL_PROCEDURE(glWaitSync);
    LOAD_OPENGL_PROCEDURE(glGetInteger64v);
    LOAD_OPENGL_PROCEDURE(glGetSynciv);
    LOAD_OPENGL_PROCEDURE(glGetInteger64i_v);
    LOAD_OPENGL_PROCEDURE(glGetBufferParameteri64v);
    LOAD_OPENGL_PROCEDURE(glGenSamplers);
    LOAD_OPENGL_PROCEDURE(glDeleteSamplers);
    LOAD_OPENGL_PROCEDURE(glIsSampler);
    LOAD_OPENGL_PROCEDURE(glBindSampler);
    LOAD_OPENGL_PROCEDURE(glSamplerParameteri);
    LOAD_OPENGL_PROCEDURE(glSamplerParameteriv);
    LOAD_OPENGL_PROCEDURE(glSamplerParameterf);
    LOAD_OPENGL_PROCEDURE(glSamplerParameterfv);
    LOAD_OPENGL_PROCEDURE(glGetSamplerParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetSamplerParameterfv);
    LOAD_OPENGL_PROCEDURE(glVertexAttribDivisor);
    LOAD_OPENGL_PROCEDURE(glBindTransformFeedback);
    LOAD_OPENGL_PROCEDURE(glDeleteTransformFeedbacks);
    LOAD_OPENGL_PROCEDURE(glGenTransformFeedbacks);
    LOAD_OPENGL_PROCEDURE(glIsTransformFeedback);
    LOAD_OPENGL_PROCEDURE(glPauseTransformFeedback);
    LOAD_OPENGL_PROCEDURE(glResumeTransformFeedback);
    LOAD_OPENGL_PROCEDURE(glGetProgramBinary);
    LOAD_OPENGL_PROCEDURE(glProgramBinary);
    LOAD_OPENGL_PROCEDURE(glProgramParameteri);
    LOAD_OPENGL_PROCEDURE(glInvalidateFramebuffer);
    LOAD_OPENGL_PROCEDURE(glInvalidateSubFramebuffer);
    LOAD_OPENGL_PROCEDURE(glTexStorage2D);
    LOAD_OPENGL_PROCEDURE(glTexStorage3D);
    LOAD_OPENGL_PROCEDURE(glGetInternalformativ);
    #undef LOAD_OPENGL_PROCEDURE
    return 1;
}

#endif//GL_ES_VERSION_3_0
// ---------------------------------------------------------------------------------------------- //