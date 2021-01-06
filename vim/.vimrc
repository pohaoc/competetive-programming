syntax on

inoremap { {}<Left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {{ {
inoremap {} {}

autocmd filetype cpp nnoremap <F8> :w <bar> !g++ -std=c++17 -Wshadow -Wall % -o %:r -O2 -DLOCAL -Wno-unused-result && ./%:r <CR>
autocmd filetype cpp nnoremap <F9> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $
:ab mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set clipboard=unnamedplus
set nu
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END
set hls
set noerrorbells
set tabstop=4 softtabstop=4
set shiftwidth=4
set expandtab
set smartindent
set nowrap
set smartcase
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch

call plug#begin('~/.vim/plugged')
Plug 'https://github.com/kien/ctrlp.vim.git'
call plug#end()

set background=dark
let mapleader = " "
let g:ctrlp_working_path_mode = 0
let g:netrw_browse_split = 2
let g:netrw_banner = 0
let g:netrw_winsize = 25

let g:ctrlp_use_caching = 0

nnoremap <leader>h :wincmd h<CR>
nnoremap <leader>j :wincmd j<CR>
nnoremap <leader>k :wincmd k<CR>
nnoremap <leader>l :wincmd l<CR>
nnoremap <leader>pv :wincmd v<bar> :Ex <bar> :vertical resize 30<CR>
nnoremap \\ :b#<CR>

