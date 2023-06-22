create database geohazard character set utf8mb4;

drop user 'geohazard'@'%';
create user 'geohazard'@'%' identified by 'Geohazard_2023_ressil';

GRANT ALL ON geohazard.* TO 'geohazard'@'%';