#ifndef __PXIT_H__
#define __PXIT_H__
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// CALLBACKS

/// @brief The function signature for application init callbacks
/// @param argc the total number of arguments
/// @param argv a array pointer of c-style arguments
typedef void (*PxitInitFunctionPtr)(int, char**);

/// @brief The function signature for application quit callbacks
typedef void (*PxitQuitFunctionPtr)();

/// @brief The function signature for application tick callbacks
/// @param t  the total elapsed time in seconds
/// @param dt the delta time since the previous tick
typedef void (*PxitTickFunctionPtr)(float, float);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ENUMERATORS

/// @brief A key identifier (PxitKey_XXX) for keyboard or mouse values
typedef enum PxitKey {
    PxitKey_MOUSE_L   = 0x01, // MOUSE     button (Left)
    PxitKey_MOUSE_R   = 0x02, // MOUSE     button (Right)
    PxitKey_MOUSE_M   = 0x04, // MOUSE     button (Middle)
    PxitKey_MOUSE_X1  = 0x05, // MOUSE     button (X1)
    PxitKey_MOUSE_X2  = 0x06, // MOUSE     button (X2)
    PxitKey_BACKSPACE = 0x08, // BACKSPACE key
    PxitKey_TAB       = 0x09, // TAB       key
    PxitKey_ENTER     = 0x0D, // ENTER     key
    PxitKey_SHIFT     = 0x10, // SHIFT     key (Left or Right)
    PxitKey_CTRL      = 0x11, // CTRL      key (Left or Right)
    PxitKey_ALT       = 0x12, // ALT       key (Left or Right)
    PxitKey_CAPS      = 0x14, // CAPS      key
    PxitKey_ESC       = 0x1B, // ESC       key
    PxitKey_SPACEBAR  = 0x20, // SPACEBAR  key
    PxitKey_ARROW_L   = 0x25, // ARROW     key (Left)
    PxitKey_ARROW_U   = 0x26, // ARROW     key (Up)
    PxitKey_ARROW_R   = 0x27, // ARROW     key (Right)
    PxitKey_ARROW_D   = 0x28, // ARROW     key (Down)
    PxitKey_DELETE    = 0x2E, // DELETE    key
    PxitKey_0         = 0x30, // 0         key
    PxitKey_1         = 0x31, // 1         key
    PxitKey_2         = 0x32, // 2         key
    PxitKey_3         = 0x33, // 3         key
    PxitKey_4         = 0x34, // 4         key
    PxitKey_5         = 0x35, // 5         key
    PxitKey_6         = 0x36, // 6         key
    PxitKey_7         = 0x37, // 7         key
    PxitKey_8         = 0x38, // 8         key
    PxitKey_9         = 0x39, // 9         key
    PxitKey_A         = 0x41, // A         key
    PxitKey_B         = 0x42, // B         key
    PxitKey_C         = 0x43, // C         key
    PxitKey_D         = 0x44, // D         key
    PxitKey_E         = 0x45, // E         key
    PxitKey_F         = 0x46, // F         key
    PxitKey_G         = 0x47, // G         key
    PxitKey_H         = 0x48, // H         key
    PxitKey_I         = 0x49, // I         key
    PxitKey_J         = 0x4A, // J         key
    PxitKey_K         = 0x4B, // K         key
    PxitKey_L         = 0x4C, // L         key
    PxitKey_M         = 0x4D, // M         key
    PxitKey_N         = 0x4E, // N         key
    PxitKey_O         = 0x4F, // O         key
    PxitKey_P         = 0x50, // P         key
    PxitKey_Q         = 0x51, // Q         key
    PxitKey_R         = 0x52, // R         key
    PxitKey_S         = 0x53, // S         key
    PxitKey_T         = 0x54, // T         key
    PxitKey_U         = 0x55, // U         key
    PxitKey_V         = 0x56, // V         key
    PxitKey_W         = 0x57, // W         key
    PxitKey_X         = 0x58, // X         key
    PxitKey_Y         = 0x59, // Y         key
    PxitKey_Z         = 0x5A, // Z         key
    PxitKey_WINDOWS   = 0x5B, // WINDOWS   key (Left or Right)
    PxitKey_MULTIPLY  = 0x6A, // MULTIPLY  key
    PxitKey_ADD       = 0x6B, // ADD       key
    PxitKey_SEPARATOR = 0x6C, // SEPARATOR key
    PxitKey_SUBTRACT  = 0x6D, // SUBTRACT  key
    PxitKey_DECIMAL   = 0x6E, // DECIMAL   key
    PxitKey_DIVIDE    = 0x6F, // DIVIDE    key
} PxitKey;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// STRUCTURES

/// @brief A set of properties that describes a new application
typedef struct PxitApplicationCreateInfo {
    PxitInitFunctionPtr OnInit; // called when application initializes
    PxitQuitFunctionPtr OnQuit; // called when application closes/quits
    PxitTickFunctionPtr OnTick; // called each frame after reading events
} PxitApplicationCreateInfo;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// API FUNCTIONS

/// @brief Creates and controls the life-cycle of a new application
/// @param info the creation information for the application
/// @param argc the total number of arguments for the entry point
/// @param argc the total number of arguments for the application
int pxitApplicationEntryPoint(const PxitApplicationCreateInfo* info, int argc, char** argv);

/// @brief Sends a close message to the currently running application
int pxitCloseApplication();

/// @brief Returns the current value of a key in a running application
/// @param key A keyboard/mouse key identifier
int pxitGetKeyValue(PxitKey key);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#ifdef __cplusplus
}
#endif//__cplusplus
#endif//__PXIT_H__