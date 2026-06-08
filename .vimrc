colorscheme slate
"colorscheme evening

set number
set relativenumber
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set scrolloff=8
set colorcolumn=120
set incsearch
set guicursor=""

" to display whitespace uncomment the below line
"set list

" search down into subfolders
set path+=**

" display matching files with tab complete
set wildmenu

" create tags using `maketags` command
command! Maketags !ctags -R .

" Move code blocks up and down
vnoremap J :m '>+1<CR>gv=gv
vnoremap K :m '<-2<CR>gv=gv

" map the leader key
let mapleader = " "

" disable highlighting for matched parenthesis
let loaded_matchparen=1

" open up netrw file explorer
nnoremap <Leader>pv :E<CR>

" go to the next file in the buffer
nnoremap <Leader>b :bn<CR>

" paste to clipboard
vnoremap <Leader>y \"+y

" remap control-c to escape
inoremap <C-c> <Esc>

" show trailing whitespace
set listchars=tab:»·,trail:◘

" Matching parens etc.
inoremap ( ()<Left>
inoremap { {}<Left>
inoremap [ []<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap " ""<Left>
inoremap ' ''<Left>
