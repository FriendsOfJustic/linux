use geohazard;

create table user_info
(
    username             varchar(50) not null primary key,
    email                varchar(128),
    avatar               varchar(256),
    current_working_area bigint
)