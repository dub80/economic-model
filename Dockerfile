FROM alpine:3.10

RUN apk add build-base \
  && apk add check-dev

COPY . ./app

WORKDIR /app

ENTRYPOINT [ "make", "test" ]
