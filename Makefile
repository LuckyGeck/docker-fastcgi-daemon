all: clean
	docker-compose build
	docker-compose up -d --force-recreate

clean:
	docker-compose kill
	docker-compose rm -f

restart:
	docker-compose restart fastcgi-daemon

build:
	docker-compose start builder