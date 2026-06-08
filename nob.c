#define NOB_IMPLEMENTATION
#include "nob.h"

const char *vim_srcs[] = {"c.vim", "glsl.vim"};

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};

    const char *home = NULL;
    if ((home = getenv("HOME")) == NULL) {
        nob_log(ERROR, "unable to find HOME environment variable please set it.");
        return 1;
    }

    const char *usr_vimrc = temp_sprintf("%s/.vimrc", home);
    String_Builder sb = {0};

    /* if another vimrc already exists rename it to .vimrc.old and create a new one */
    if (file_exists(usr_vimrc)) {
        const char *backup = temp_sprintf("%s.old", usr_vimrc);
        nob_log(WARNING, ".vimrc already exists creating backup %s", backup);
        if (!read_entire_file(usr_vimrc, &sb)) return 1;
        if (!nob_rename(usr_vimrc, backup)) return 1;
    }

    if (!copy_file(".vimrc", usr_vimrc)) return 1;

    /* create the plugin directories */
    const char *vim_dir = temp_sprintf("%s/.vim", home);
    const char *after_dir = temp_sprintf("%s/after", vim_dir);
    const char *syntax_dir = temp_sprintf("%s/syntax", after_dir);
    if (!mkdir_if_not_exists(vim_dir)) return 1;
    if (!mkdir_if_not_exists(after_dir)) return 1;
    if (!mkdir_if_not_exists(syntax_dir)) return 1;

    /* copy over vim srcs */
    for (size_t i = 0; i < ARRAY_LEN(vim_srcs); i++) {
        const char *src = temp_sprintf("%s/%s", syntax_dir, vim_srcs[i]);
        if (!copy_file(vim_srcs[i], src)) return 1;
    }

    return 0;
}
