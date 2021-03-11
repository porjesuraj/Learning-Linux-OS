#!/bin/bash

declare -a arr=( \
	"openjdk-8-jdk" "openjdk-8-doc" "openjfx"
	"gcc-multilib" "g++" "g++-4.8-multilib" "valgrind"
	"lib32z1" "lib32ncurses5" "lib32stdc++6" "make"
	"ssh" "vim" "cscope" "p7zip-full" "libncurses5-dev" \
	"code" "xmlcopyeditor" \
	 \
	"apache2" "mysql-community-server" "mysql-community-client"
	"mongodb-org" "mongodb-org-tools" \
	"php7.2" "php7.2-mysql" "php7.2-curl" "php7.2-json" \
	"php-mbstring" "php7.2-mbstring" "php7.2-gettext" "libapache2-mod-php7.2" \
	"git"  \
	"aptitude" "gnome-tweak-tool" "vlc" "google-chrome-stable" "unrar" "net-tools"\
	  \
	)


if [ $EUID -ne 0 ]
then
	echo "Please execute this script as root --- sudo"
	exit 1
fi

echo "You are authorized to run this script now ..."

if [ -d /home/$SUDO_USER/subuntu2020/repo ]
then

## take backup of existing sources.list
if [ `wc -l /etc/apt/sources.list` -gt 4 ]
then
	cp /etc/apt/sources.list /etc/apt/sources.list.bak
fi

## copy and mount iso image
# sudo cp /media/$USER/SONY_32GR/subuntu-pkgs-v1.iso /
# sudo mkdir /repo
# sudo mount /subuntu-pkgs-v1.iso /repo -o loop,ro

## modify existing sources.list
echo "deb [ allow-insecure=yes ] file:///home/$SUDO_USER/subuntu2020/repo/ /" > /etc/apt/sources.list

## update repos -- gives warning that repo is unauthenticated - ignore it.
apt-get update
if [ $? -ne 0 ]
then
	echo "***********************************************************************"
	echo "apt-get update is failed."
	echo "also verify whether /etc/apt/sources.list is configured properly."
	echo "***********************************************************************"
	exit 
fi

for pkg in "${arr[@]}"
do
	echo "******************** installing $pkg ..."
	apt-get -y --allow-unauthenticated install $pkg
	if [ $? -eq 0 ]
	then
		echo "******************** $pkg installed successfully ..."
	else
		echo "******************** $pkg failed to install ..."
		break
	fi
done

else
	echo "first extract repo tar file into /home/$SUDO_USER/ directory..."
fi


