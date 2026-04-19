#!/bin/bash

echo "Bootstrapping Project ..."

echo "Setting up backend config ..."

PROJECT_ROOT=$(pwd)
PROJECT_BACKEND_ROOT="${PROJECT_ROOT}/backend"
PROJECT_TESTBED_ROOT="${PROJECT_ROOT}/testbed"

export PROJECT_ROOT
export PROJECT_BACKEND_ROOT

mkdir -p "${PROJECT_BACKEND_ROOT}/tmp"

if [ ! -f "${PROJECT_BACKEND_ROOT}/.env" ]; then 
    cp "${PROJECT_BACKEND_ROOT}/.env.example" "${PROJECT_BACKEND_ROOT}/.env"
fi

echo "Done setting backend !"
echo "That's all folks! Happy Hacking :)"