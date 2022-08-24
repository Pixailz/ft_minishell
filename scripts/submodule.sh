#!/bin/bash

#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#==#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
#> Global config

CWD="$(pwd)/"
declare -a SUBMODULES_LIST

red="\x1b[38;5;196m"
green="\x1b[38;5;82m"
blue="\x1b[38;5;75m"
orange="\x1b[38;5;214m"

blink="\x1b[5m"
reset="\x1b[0m"
text=${blue}
bold=${green}

SUCCESS="${text}[${green}+${text}]${reset}"
FAILED="${text}[${red}-${text}]${reset}"
WARN="${text}[${orange}*${text}]${reset}"
#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#==#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#==#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
#> utils

function p_warn()
{
	if [ ! -z ${2} ]; then
		printf "${WARN} ${text}${1}. (${bold}${2}${text})${reset}\n"
	else
		printf "${WARN} ${text}${1}.${reset}\n"
	fi
}

function p_info()
{
	if [ ! -z ${2} ]; then
		printf "${SUCCESS} ${text}${1}. (${bold}${2}${text})${reset}\n"
	else
		printf "${SUCCESS} ${text}${1}.${reset}\n"
	fi
}

#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#==#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#


function get_submodules()
{
	for module in $(sed -nE 's|\[submodule "(.*)"\]$|\1|p' \
														${CWD}.gitmodules); do
		SUBMODULES_LIST+=("${CWD}${module}")
	done
}

function print_submodules()
{
	for element in ${SUBMODULES_LIST[@]}; do
		printf "NAME:\t%s\n" "${element/${CWD}}"
		printf "PATH:\t%s\n" "${element}"
		printf "\n"
	done
}

function init_submodule()
{
	# init_module if not initialised
	if [ ! -f "${submodule}/.git" ]; then
		git submodule init "${1}"
		git submodule update "${1}" 1>/dev/null
		p_warn "Submodule initialised" ${1}
	fi
}

function update_submodule()
{
	SUB_CURRENT_COMMIT_TMP=$(git submodule status | grep ${1/${CWD}})
	SUB_CURRENT_BRANCH=$(echo "${SUB_CURRENT_COMMIT_TMP}" | \
								sed -nE "s|.*/(.*)\)$|\1|p")
	SUB_CURRENT_COMMIT_ID=$(echo "${SUB_CURRENT_COMMIT_TMP}" | \
								sed -nE "s|.*([0-9a-f]{40}).*|\1|p")
	cd ${1/${CWD}}
	SUB_LAST_COMMIT_ID=$(git log --format="%H" -n 1 \
								 --branches origin/${SUB_CURRENT_BRANCH})
	if [ "${SUB_LAST_COMMIT_ID}" != "${SUB_CURRENT_COMMIT_ID}" ]; then
		p_warn "Submodule need update" "${1/${CWD}}"
		git merge origin/${SUB_CURRENT_BRANCH}
		cd ${CWD}
		git add ${1/${CWD}}
		git commit -m ":package: ${1/${CWD}}:
- ${SUB_CURRENT_COMMIT_ID:0:7} updated to ${SUB_LAST_COMMIT_ID:0:7}"
		#git push
		p_info "Submodule updated" "${1/${CWD}}"
	else
		p_info "Submodule already up to date" "${1/${CWD}}"
	fi
	cd ${CWD}
}

function main()
{
	get_submodules
	for submodule in ${SUBMODULES_LIST[@]}; do
		p_info "Submodule found" ${submodule/${CWD}}
		init_submodule "${submodule}"
		update_submodule "${submodule}"
	done
}

main
