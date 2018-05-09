create table manager
(
    managerid         char(4)             not null,
    mfname            varchar(15)         not null,
    mlname            varchar(15)         not null,
    mbdate            date                not null,
    msalary           numeric(9, 2)       not null,
    mbonous           numeric(9, 2),
    mresbuildingid    char(3),
    PRIMARY KEY ( managerid )
);
create table managerphone
(
    managerid          char(4)            not null,
    mphone             char(11)           not null,
    PRIMARY KEY ( managerid, mphone ),
    FOREIGN KEY ( managerid ) REFERENCES manager( managerid )
);
create table building
(
    buildingid         char(3)            not NULL,
    bnooffloors        int                not null,
    bmanagerid         char(4)            not null,
    PRIMARY KEY ( buildingid ),
    FOREIGN KEY ( bmanagerid ) REFERENCES manager( managerid )
);
create table inspector
(
    insid              char(3)             not null,
    insname            varchar(15)         not null,
    PRIMARY KEY ( insid )
);
create table inspecting
(
    insid              char(3)             not null,
    buildingid         char(3)             not null,
    datelast           date                not null,
    datenext           date                not null,
    PRIMARY KEY ( insid, buildingid ),
    FOREIGN KEY ( insid ) REFERENCES inspector( insid ),
    FOREIGN KEY ( buildingid ) REFERENCES building( buildingid )
);
create table corpclient
(
    ccid               char(4)             not null,
    ccname             varchar(25)         not null,
    ccinductry         varchar(25)         not null,
    cclocation         varchar(25)         not null,
    ccidreferredby     char(4),
    PRIMARY KEY ( ccid ),
    UNIQUE ( ccname ),
    FOREIGN KEY ( ccidreferredby ) REFERENCES corpclient( ccid )
);
create table appartment
(
    buildingid          char(3)           not null,
    aptno               char(5)           not null,
    anoofbedrooms       int               not null,
    ccid                char(4),
    PRIMARY KEY ( buildingid, aptno ),
    FOREIGN KEY ( buildingid ) REFERENCES building( buildingid ),
    FOREIGN KEY ( ccid ) REFERENCES corpclient( ccid )
);
create table staffmember
(
    smemberid           char(4)          not null,
    smembername         varchar(15)      not null,
    PRIMARY KEY ( smemberid )
);
create table cleaning
(
    buildingid          char(3)          not null,
    aptno               char(5)          not null,
    smemberid           char(4)          not null,
    CONSTRAINT cleaningpk PRIMARY KEY ( buildingid, aptno, smemberid ),
    CONSTRAINT cleaningfk1 FOREIGN KEY ( buildingid, aptno ) references appartment( buildingid, aptno ),
    CONSTRAINT cleaningfk2 FOREIGN KEY ( smemberid ) references staffmember( smemberid )
);
