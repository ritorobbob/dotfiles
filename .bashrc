# .bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
PS1='[\u@\h \W]\$ '

alias v="nvim"
alias r="ranger"
alias i3c="vim ~/.config/i3/config"
alias nvc="nvim ~/.config/nvim/init.vim"
alias xup="xrdb ~/.Xresources"
alias shutdown="sudo shutdown -h now"
alias pkgs="sudo xbps-query -Rs"
alias pkgi="sudo xbps-install"
alias gitdotfiles="/usr/bin/git --git-dir=$HOME/.dotfiles/ --work-tree=$HOME"
shopt -s cdable_vars
xset r rate 200 20

#export config=$HOME/.config
