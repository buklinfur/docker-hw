#!/bin/sh

until docker ps -f name=candle-app-container -f status=exited | grep candle-app-container; do
    sleep 1
done

docker logs candle-app-container > /usr/share/nginx/html/index.html

exec nginx -g 'daemon off;'