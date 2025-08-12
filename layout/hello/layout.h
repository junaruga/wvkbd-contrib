/* constants */
/* how tall the keyboard should be by default (can be overriden) */
#define KBD_PIXEL_HEIGHT 400

/* how tall the keyboard should be by default (can be overriden) */
#define KBD_PIXEL_LANDSCAPE_HEIGHT 400

/* spacing around each key */
#define KBD_KEY_BORDER 2

/* layout declarations */
enum layout_id {
  Full = 0,
  Special,
  Index,
  NumLayouts,
};

static struct key keys_full[], keys_special[], keys_index[];

static struct layout layouts[NumLayouts] = {
    /*
     * second parameter is the keymap name
     * third parameter is the layout name
     * last parameter indicates if it's an alphabetical/primary
     * layout
     */
    [Full] = {keys_full, "latin", "full", true},
    [Special] = {keys_special, "latin", "special", false},
    [Index] = {keys_index, "latin", "index", false},
};

/* key layouts
 *
 * define keys like:
 *
 *  `{
 *     "label",
 *     "SHIFT_LABEL",
 *     1,
 *     [Code, Mod, Layout, EndRow, Last],
 *     [KEY_CODE, Modifier],
 *     [&layout]
 *  },`
 *
 * - label: normal label for key
 *
 * - shift_label: label for key in shifted (uppercase) layout
 *
 * - width: column width of key
 *
 * - type: what kind of action this key peforms (emit keycode, toggle modifier,
 *   switch layout, or end the layout)
 *
 * - code: key scancode or modifier name (see
 *   `/usr/include/linux/input-event-codes.h` for scancode names, and
 *   `keyboard.h` for modifiers)
 *
 * - layout: layout to switch to when key is pressed
 */
static struct key keys_full[] = {
    {"", "", 12.0, Pad},
    {"", "", 0.0, EndRow},

    {"h", "H", 1.0, Code, KEY_H},
    {"e", "E", 1.0, Code, KEY_E},
    {"l", "L", 1.0, Code, KEY_L},
    {"l", "L", 1.0, Code, KEY_L},
    {"o", "O", 1.0, Code, KEY_O},
    {"", "", 2.0, Pad},
    {"w", "W", 1.0, Code, KEY_W},
    {"o", "O", 1.0, Code, KEY_O},
    {"r", "R", 1.0, Code, KEY_R},
    {"l", "L", 1.0, Code, KEY_L},
    {"d", "D", 1.0, Code, KEY_D},
    {"", "", 0.0, EndRow},

    {"⌨͕", "⌨͔", 1.0, NextLayer, .scheme = 1},
    {"Cmp", "Cmp", 1.0, Compose, .scheme = 1},
    {"⇧", "⇫", 2.0, Mod, Shift, .scheme = 1},
    {"", "", 4.0, Code, KEY_SPACE},
    {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},
    {"⇧", "⇫", 2.0, Mod, Shift, .scheme = 1},

    {"", "", 0.0, EndRow},

    /* end of layout */
    {"", "", 0.0, Last},
};

static struct key keys_special[] = {
    {"", "", 12.0, Pad},
    {"", "", 0.0, EndRow},

    {"", "", 12.0, Pad},
    {"", "", 0.0, EndRow},

    {"⌨͕", "⌨͔", 1.0, NextLayer, .scheme = 1},
    {"", "", 11.0, Pad},
    {"", "", 0.0, EndRow},

    /* end of layout */
    {"", "", 0.0, Last},
};

static struct key keys_index[] = {
    {"Full", "Full", 1.0, Layout, 0, &layouts[Full], .scheme = 1},
    {"Special", "Special", 1.0, Layout, 0, &layouts[Special], .scheme = 1},
    {"", "", 0.0, Last},
};
