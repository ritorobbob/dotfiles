#!/bin/bash -x

xrdb $HOME/.Xresources
feh --bg-center $HOME/.config/void-flag.png
$HOME/.scripts/statusBar &
xset r rate 200 20
exec dwm

