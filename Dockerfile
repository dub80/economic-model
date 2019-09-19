FROM alpine:3.10.2

RUN apk upgrade --update \
  && apk add build-base \
  && apk add gsl-dev \
  && apk add check-dev

COPY . ./app

WORKDIR /app
