#!/bin/bash

awk '$1 == "ATOM" || $1 == "HETATM" { count++} END { print count;}'