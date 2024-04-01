#ifndef __gles2_gl32_h_
#define __gles2_gl32_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

/*
** Copyright 2013-2020 The Khronos Group Inc.
** SPDX-License-Identifier: MIT
**
** This header is generated from the Khronos OpenGL / OpenGL ES XML
** API Registry. The current version of the Registry, generator scripts
** used to make the header, and the header can be found at
**   https://github.com/KhronosGroup/OpenGL-Registry
*/

/* Generated on date 20191013 */
/* Modified on date 20240401 */

/* Generated C header for:
 * API: gles2
 * Profile: common
 * Versions considered: 2\.[0-9]|3\.[012]
 * Versions emitted: .*
 * Default extensions included: None
 * Additional extensions included: _nomatch_^
 * Extensions removed: _nomatch_^
 */

#include <GLES3/gl31.h>

#ifndef GL_ES_VERSION_3_2
#define GL_ES_VERSION_3_2 1
typedef void (GL_APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE                    0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY              0x9382
#define GL_MULTIPLY                                        0x9294
#define GL_SCREEN                                          0x9295
#define GL_OVERLAY                                         0x9296
#define GL_DARKEN                                          0x9297
#define GL_LIGHTEN                                         0x9298
#define GL_COLORDODGE                                      0x9299
#define GL_COLORBURN                                       0x929A
#define GL_HARDLIGHT                                       0x929B
#define GL_SOFTLIGHT                                       0x929C
#define GL_DIFFERENCE                                      0x929E
#define GL_EXCLUSION                                       0x92A0
#define GL_HSL_HUE                                         0x92AD
#define GL_HSL_SATURATION                                  0x92AE
#define GL_HSL_COLOR                                       0x92AF
#define GL_HSL_LUMINOSITY                                  0x92B0
#define GL_DEBUG_OUTPUT_SYNCHRONOUS                        0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                0x8243
#define GL_DEBUG_CALLBACK_FUNCTION                         0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM                       0x8245
#define GL_DEBUG_SOURCE_API                                0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM                      0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER                    0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY                        0x8249
#define GL_DEBUG_SOURCE_APPLICATION                        0x824A
#define GL_DEBUG_SOURCE_OTHER                              0x824B
#define GL_DEBUG_TYPE_ERROR                                0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                  0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                   0x824E
#define GL_DEBUG_TYPE_PORTABILITY                          0x824F
#define GL_DEBUG_TYPE_PERFORMANCE                          0x8250
#define GL_DEBUG_TYPE_OTHER                                0x8251
#define GL_DEBUG_TYPE_MARKER                               0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP                           0x8269
#define GL_DEBUG_TYPE_POP_GROUP                            0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION                     0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH                     0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH                         0x826D
#define GL_BUFFER                                          0x82E0
#define GL_SHADER                                          0x82E1
#define GL_PROGRAM                                         0x82E2
#define GL_VERTEX_ARRAY                                    0x8074
#define GL_QUERY                                           0x82E3
#define GL_PROGRAM_PIPELINE                                0x82E4
#define GL_SAMPLER                                         0x82E6
#define GL_MAX_LABEL_LENGTH                                0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH                        0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES                       0x9144
#define GL_DEBUG_LOGGED_MESSAGES                           0x9145
#define GL_DEBUG_SEVERITY_HIGH                             0x9146
#define GL_DEBUG_SEVERITY_MEDIUM                           0x9147
#define GL_DEBUG_SEVERITY_LOW                              0x9148
#define GL_DEBUG_OUTPUT                                    0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT                          0x00000002
#define GL_STACK_OVERFLOW                                  0x0503
#define GL_STACK_UNDERFLOW                                 0x0504
#define GL_GEOMETRY_SHADER                                 0x8DD9
#define GL_GEOMETRY_SHADER_BIT                             0x00000004
#define GL_GEOMETRY_VERTICES_OUT                           0x8916
#define GL_GEOMETRY_INPUT_TYPE                             0x8917
#define GL_GEOMETRY_OUTPUT_TYPE                            0x8918
#define GL_GEOMETRY_SHADER_INVOCATIONS                     0x887F
#define GL_LAYER_PROVOKING_VERTEX                          0x825E
#define GL_LINES_ADJACENCY                                 0x000A
#define GL_LINE_STRIP_ADJACENCY                            0x000B
#define GL_TRIANGLES_ADJACENCY                             0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY                        0x000D
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS                 0x8DDF
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS                     0x8A2C
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS        0x8A32
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS                   0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS                  0x9124
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES                    0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS            0x8DE1
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS                 0x8E5A
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS                0x8C29
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS             0x92CF
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS                    0x92D5
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS                     0x90CD
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS              0x90D7
#define GL_FIRST_VERTEX_CONVENTION                         0x8E4D
#define GL_LAST_VERTEX_CONVENTION                          0x8E4E
#define GL_UNDEFINED_VERTEX                                0x8260
#define GL_PRIMITIVES_GENERATED                            0x8C87
#define GL_FRAMEBUFFER_DEFAULT_LAYERS                      0x9312
#define GL_MAX_FRAMEBUFFER_LAYERS                          0x9317
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS            0x8DA8
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED                  0x8DA7
#define GL_REFERENCED_BY_GEOMETRY_SHADER                   0x9309
#define GL_PRIMITIVE_BOUNDING_BOX                          0x92BE
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT                  0x00000004
#define GL_CONTEXT_FLAGS                                   0x821E
#define GL_LOSE_CONTEXT_ON_RESET                           0x8252
#define GL_GUILTY_CONTEXT_RESET                            0x8253
#define GL_INNOCENT_CONTEXT_RESET                          0x8254
#define GL_UNKNOWN_CONTEXT_RESET                           0x8255
#define GL_RESET_NOTIFICATION_STRATEGY                     0x8256
#define GL_NO_RESET_NOTIFICATION                           0x8261
#define GL_CONTEXT_LOST                                    0x0507
#define GL_SAMPLE_SHADING                                  0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE                        0x8C37
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET               0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET               0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS              0x8E5D
#define GL_PATCHES                                         0x000E
#define GL_PATCH_VERTICES                                  0x8E72
#define GL_TESS_CONTROL_OUTPUT_VERTICES                    0x8E75
#define GL_TESS_GEN_MODE                                   0x8E76
#define GL_TESS_GEN_SPACING                                0x8E77
#define GL_TESS_GEN_VERTEX_ORDER                           0x8E78
#define GL_TESS_GEN_POINT_MODE                             0x8E79
#define GL_ISOLINES                                        0x8E7A
#define GL_QUADS                                           0x0007
#define GL_FRACTIONAL_ODD                                  0x8E7B
#define GL_FRACTIONAL_EVEN                                 0x8E7C
#define GL_MAX_PATCH_VERTICES                              0x8E7D
#define GL_MAX_TESS_GEN_LEVEL                              0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS             0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS          0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS            0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS         0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS              0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS                       0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS        0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS           0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS              0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS               0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS            0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS    0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS         0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS      0x92CE
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS             0x92D4
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS              0x90CC
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS          0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS       0x90D9
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED         0x8221
#define GL_IS_PER_PATCH                                    0x92E7
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER               0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER            0x9308
#define GL_TESS_CONTROL_SHADER                             0x8E88
#define GL_TESS_EVALUATION_SHADER                          0x8E87
#define GL_TESS_CONTROL_SHADER_BIT                         0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT                      0x00000010
#define GL_TEXTURE_BORDER_COLOR                            0x1004
#define GL_CLAMP_TO_BORDER                                 0x812D
#define GL_TEXTURE_BUFFER                                  0x8C2A
#define GL_TEXTURE_BUFFER_BINDING                          0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE                         0x8C2B
#define GL_TEXTURE_BINDING_BUFFER                          0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING               0x8C2D
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                 0x919F
#define GL_SAMPLER_BUFFER                                  0x8DC2
#define GL_INT_SAMPLER_BUFFER                              0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_BUFFER                     0x8DD8
#define GL_IMAGE_BUFFER                                    0x9051
#define GL_INT_IMAGE_BUFFER                                0x905C
#define GL_UNSIGNED_INT_IMAGE_BUFFER                       0x9067
#define GL_TEXTURE_BUFFER_OFFSET                           0x919D
#define GL_TEXTURE_BUFFER_SIZE                             0x919E
#define GL_COMPRESSED_RGBA_ASTC_4x4                        0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4                        0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5                        0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5                        0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6                        0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5                        0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6                        0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8                        0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5                       0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6                       0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8                       0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10                      0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10                      0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12                      0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4                0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4                0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5                0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5                0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6                0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5                0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6                0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8                0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5               0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6               0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8               0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10              0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10              0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12              0x93DD
#define GL_TEXTURE_CUBE_MAP_ARRAY                          0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                  0x900A
#define GL_SAMPLER_CUBE_MAP_ARRAY                          0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                   0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY                      0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY             0x900F
#define GL_IMAGE_CUBE_MAP_ARRAY                            0x9054
#define GL_INT_IMAGE_CUBE_MAP_ARRAY                        0x905F
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY               0x906A
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY                    0x9102
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY            0x9105
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY                    0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY       0x910D
typedef void      (GL_APIENTRYP PFN_glBlendBarrier) (void);
typedef void      (GL_APIENTRYP PFN_glCopyImageSubData) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void      (GL_APIENTRYP PFN_glDebugMessageControl) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void      (GL_APIENTRYP PFN_glDebugMessageInsert) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void      (GL_APIENTRYP PFN_glDebugMessageCallback) (GLDEBUGPROC callback, const void *userParam);
typedef GLuint    (GL_APIENTRYP PFN_glGetDebugMessageLog) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void      (GL_APIENTRYP PFN_glPushDebugGroup) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void      (GL_APIENTRYP PFN_glPopDebugGroup) (void);
typedef void      (GL_APIENTRYP PFN_glObjectLabel) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void      (GL_APIENTRYP PFN_glGetObjectLabel) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void      (GL_APIENTRYP PFN_glObjectPtrLabel) (const void *ptr, GLsizei length, const GLchar *label);
typedef void      (GL_APIENTRYP PFN_glGetObjectPtrLabel) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void      (GL_APIENTRYP PFN_glGetPointerv) (GLenum pname, void **params);
typedef void      (GL_APIENTRYP PFN_glEnablei) (GLenum target, GLuint index);
typedef void      (GL_APIENTRYP PFN_glDisablei) (GLenum target, GLuint index);
typedef void      (GL_APIENTRYP PFN_glBlendEquationi) (GLuint buf, GLenum mode);
typedef void      (GL_APIENTRYP PFN_glBlendEquationSeparatei) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void      (GL_APIENTRYP PFN_glBlendFunci) (GLuint buf, GLenum src, GLenum dst);
typedef void      (GL_APIENTRYP PFN_glBlendFuncSeparatei) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void      (GL_APIENTRYP PFN_glColorMaski) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef GLboolean (GL_APIENTRYP PFN_glIsEnabledi) (GLenum target, GLuint index);
typedef void      (GL_APIENTRYP PFN_glDrawElementsBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void      (GL_APIENTRYP PFN_glDrawRangeElementsBaseVertex) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void      (GL_APIENTRYP PFN_glDrawElementsInstancedBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void      (GL_APIENTRYP PFN_glFramebufferTexture) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void      (GL_APIENTRYP PFN_glPrimitiveBoundingBox) (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
typedef GLenum    (GL_APIENTRYP PFN_glGetGraphicsResetStatus) (void);
typedef void      (GL_APIENTRYP PFN_glReadnPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void      (GL_APIENTRYP PFN_glGetnUniformfv) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void      (GL_APIENTRYP PFN_glGetnUniformiv) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void      (GL_APIENTRYP PFN_glGetnUniformuiv) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void      (GL_APIENTRYP PFN_glMinSampleShading) (GLfloat value);
typedef void      (GL_APIENTRYP PFN_glPatchParameteri) (GLenum pname, GLint value);
typedef void      (GL_APIENTRYP PFN_glTexParameterIiv) (GLenum target, GLenum pname, const GLint *params);
typedef void      (GL_APIENTRYP PFN_glTexParameterIuiv) (GLenum target, GLenum pname, const GLuint *params);
typedef void      (GL_APIENTRYP PFN_glGetTexParameterIiv) (GLenum target, GLenum pname, GLint *params);
typedef void      (GL_APIENTRYP PFN_glGetTexParameterIuiv) (GLenum target, GLenum pname, GLuint *params);
typedef void      (GL_APIENTRYP PFN_glSamplerParameterIiv) (GLuint sampler, GLenum pname, const GLint *param);
typedef void      (GL_APIENTRYP PFN_glSamplerParameterIuiv) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void      (GL_APIENTRYP PFN_glGetSamplerParameterIiv) (GLuint sampler, GLenum pname, GLint *params);
typedef void      (GL_APIENTRYP PFN_glGetSamplerParameterIuiv) (GLuint sampler, GLenum pname, GLuint *params);
typedef void      (GL_APIENTRYP PFN_glTexBuffer) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void      (GL_APIENTRYP PFN_glTexBufferRange) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void      (GL_APIENTRYP PFN_glTexStorage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#endif /* GL_ES_VERSION_3_2 */

#ifdef __cplusplus
}
#endif

#endif