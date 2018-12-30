" Specify a directory for plugins
" - For Neovim: ~/.local/share/nvim/plugged
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.local/share/nvim/plugged')

if has('nvim')
  Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
else
  Plug 'Shougo/deoplete.nvim'
  Plug 'roxma/nvim-yarp'
  Plug 'roxma/vim-hug-neovim-rpc'
endif

Plug 'zchee/deoplete-jedi'
Plug 'zchee/deoplete-clang'


Plug 'junegunn/seoul256.vim'
Plug 'lilydjwg/colorizer'
call plug#end()
colo seoul256

let g:deoplete#enable_at_startup = 1
"must set the path to clang with this command: ([sudo] find / -name libclang.so)
let g:deoplete#sources#clang#libclang_path = '/usr/lib/libc.so'
let g:python_host_prog = '/usr/bin/python2.7'
let g:python3_host_prog = '/usr/bin/python3.6'

" General
set number
set relativenumber
set encoding=utf-8
set linebreak
set showbreak=+++ 
set textwidth=100
set showmatch
set visualbell

set hlsearch
set smartcase
set ignorecase
set incsearch

set tabstop=4
set autoindent
set shiftwidth=4
"set smartindent
set smarttab
set softtabstop=0
set expandtab

" Advanced
set ruler
set wildmode=longest,list,full
set wildmenu

filetype indent on
filetype plugin on

syntax on

"deoplete colours
highlight Pmenu ctermbg=8 ctermfg=7 
highlight PmenuSel ctermbg=3 ctermfg=14
highlight PmenuSbar ctermfg=14 ctermbg=8 guifg=#333333
"sets it so deoplete doesnt show scratch preview
set completeopt-=preview

set undolevels=1000
set backspace=indent,eol,start

hi Normal guibg=NONE ctermbg=NONE
hi LineNR guibg=NONE ctermbg=NONE
hi CursorLineNr guibg=NONE ctermbg=NONE

"run and compile keybinds
nnoremap !! :w <CR> :! gcc % -o ./%.out && ./%.out <CR>
nnoremap !p :w <CR> :! python3 ./% <CR>

nnoremap <Esc> :noh <CR>
nnoremap <Tab> 0I<Tab><Esc><CR>
nnoremap <S><Tab> 04x<CR>
tnoremap <Esc> <C-\><C-n>
"vv to highlight current line
nnoremap vv $v0h
autocmd FileType python nnoremap ;c 0i#<Esc><CR>  
