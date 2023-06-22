use geohazard;

create table Landslide
(
    id     int primary key auto_increment,
    volume double comment '滑坡体积',
    theta  double comment '坡度',
    height double comment '高度'
) engine InnoDB;

insert into Landslide(volume, theta, height)
values (1, 2, 3),
       (2, 2, 3),
       (3, 2, 3),
       (4, 2, 3);
