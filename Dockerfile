FROM alpine:3.8.4

RUN apk upgrade --update \
  && apk add build-base \
  && apk --no-cache add gsl gsl-dev \
  && apk add check-dev

COPY . ./app

WORKDIR /app
