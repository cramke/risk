## Overview
PostGIS runs in the official docker image under Windows, while this SW runs in WSL2.

## Setup
1. Docker Desktop (Windows)
2. Settings - Ressources - WSL - (activate respective wsl)
3. To verify installation: WSL -> docker --version
4. To clone docker image: WSL -> docker pull postgis/postgis
5. Run docker image: WSL -> docker run --name some-postgis -e POSTGRES_PASSWORD=postgis -d -p 5432:5432 postgis/postgis
    a.  Start container image again -> sudo docker start 2b60221df50f0c9fef5bf28222e72f931c128580c6c49570c367324ff2d7ca7f
6. Connect with psql to database: WSL -> docker exec -ti some-postgis psql -U postgres

## Create Table 

CREATE TABLE some_points (
    id BIGSERIAL PRIMARY KEY,
    risk double precision
);

SELECT AddGeometryColumn('some_points', 'wkb_geometry', 4326, 'POINT', 2);

INSERT INTO some_points(risk, wkb_geometry)                                           
VALUES(5, ST_GeomFromText('POINT(-71.060316 48.432044)', 4326));

INSERT INTO some_points(risk, wkb_geometry)                                           
VALUES(0, ST_GeomFromText('POINT(-17.060316 123.432044)', 4326));

INSERT INTO some_points(risk, wkb_geometry)                                           
VALUES(9, ST_GeomFromText('POINT(71.060316 -48.432044)', 4326));

INSERT INTO some_points(risk, wkb_geometry)                                           
VALUES(5, ST_GeomFromText('POINT(026.060316 12.432044)', 4326));

sudo docker start 2b60221df50f0c9fef5bf28222e72f931c128580c6c49570c367324ff2d7ca7f

SELECT * FROM some_points;

DROP TABLE some_points;

SELECT risk, wkb_geometry <-> ST_GeomFromText('POINT(-71.060316 49.432044)', 4326) AS dist FROM some_points ORDER BY dist;