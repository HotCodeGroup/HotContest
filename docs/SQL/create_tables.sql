CREATE TABLE profile (
    user_id SERIAL PRIMARY KEY,
    first_name  VARCHAR(64) NOT NULL,
    last_name VARCHAR(64) NOT NULL,
    nickname VARCHAR(64) UNIQUE NOT NULL,
    email VARCHAR(64) UNIQUE NOT NULL,
    password VARCHAR(64) NOT NULL,

    date_joined TIMESTAMP DEFAULT NOW(),
    is_active BOOLEAN NOT NULL DEFAULT TRUE
);

CREATE TABLE contest (
    contest_id SERIAL PRIMARY KEY,
    title VARCHAR(64) NOT NULL,
    description TEXT,
    start_time TIMESTAMP WITH TIME ZONE,
    finish_time TIMESTAMP WITH TIME ZONE,
    is_private BOOLEAN DEFAULT FALSE,

    is_active BOOLEAN NOT NULL DEFAULT TRUE
);

CREATE TABLE Participant (
    user_id INTEGER REFERENCES Profile (user_id) ON DELETE SET NULL,
    contest_id INTEGER REFERENCES Contest (contest_id) ON DELETE SET NULL
);

CREATE TABLE Organizers (
    user_id INTEGER REFERENCES Profile (user_id) ON DELETE SET NULL,
    contest_id INTEGER REFERENCES Contest (contest_id) ON DELETE SET NULL
);

CREATE TABLE AccessList (
    user_id INTEGER REFERENCES Profile (user_id) ON DELETE SET NULL,
    contest_id INTEGER REFERENCES Contest (contest_id) ON DELETE SET NULL
);

CREATE TABLE problem (
    problem_id SERIAL PRIMARY KEY,
    title VARCHAR(64) NOT NULL,
    description TEXT,
    time_limit INTEGER NOT NULL DEFAULT 1000 CHECK (time_limit > 0),
    memory_limit INTEGER NOT NULL DEFAULT 1024 CHECK (memory_limit > 0),
    tries_left INTEGER NOT NULL DEFAULT 100 CHECK (tries_left > 0),
    points INTEGER NOT NULL DEFAULT 0 CHECK (points >= 0),
    penalty_try INTEGER NOT NULL DEFAULT 0 CHECK (penalty_try >= 0),
    penalty_time INTEGER NOT NULL DEFAULT 0 CHECK (penalty_time >= 0),

    contest_id INTEGER REFERENCES Contest (contest_id) ON DELETE CASCADE
);

CREATE TABLE solution (
    solution_id SERIAL PRIMARY KEY,
    src_file VARCHAR(256) NOT NULL,
    submit_time TIMESTAMP DEFAULT NOW(),

    problem_id INTEGER REFERENCES Problem (problem_id) ON DELETE CASCADE,
    user_id INTEGER REFERENCES Profile (user_id) ON DELETE SET NULL
);

CREATE TABLE submit (
    submit_id SERIAL PRIMARY KEY,
    resp_code VARCHAR(64) NOT NULL,
    error_test INTEGER CHECK (error_test > 0),
    time INTEGER NOT NULL CHECK (time > 0),
    memory INTEGER NOT NULL CHECK (memory > 0),

    solution_id INTEGER REFERENCES Solution (solution_id) ON DELETE CASCADE UNIQUE
);

CREATE TABLE test (
    test_id SERIAL PRIMARY KEY,
    input VARCHAR(256) NOT NULL,
    output VARCHAR(256) NOT NULL,

    problem_id INTEGER REFERENCES Problem (problem_id) ON DELETE CASCADE
);

CREATE TABLE test_submit (
    test_submit_id SERIAL PRIMARY KEY,
    verdict VARCHAR(64) NOT NULL,

    time INTEGER NOT NULL CHECK (time > 0),
    memory INTEGER NOT NULL CHECK (memory > 0),

    test_id INTEGER REFERENCES Test (test_id) ON DELETE CASCADE UNIQUE,
    submit_id INTEGER REFERENCES Submit (submit_id) ON DELETE CASCADE
);

CREATE TABLE invitation (
    invitation_id SERIAL PRIMARY KEY,
    state INTEGER DEFAULT 0,

    sender_id INTEGER REFERENCES Profile (user_id) ON DELETE SET NULL,
    addresse_id INTEGER REFERENCES Profile (user_id) ON DELETE CASCADE,
    contest_id INTEGER REFERENCES Contest (contest_id) ON DELETE CASCADE
);

CREATE TABLE message (
    message_id SERIAL PRIMARY KEY,
    text VARCHAR(512),
    time_stamp TIMESTAMP DEFAULT NOW(),

    author_id INTEGER REFERENCES Profile (user_id) ON DELETE CASCADE,
    contest_id INTEGER REFERENCES Contest (contest_id) ON DELETE CASCADE
);

CREATE TABLE blog (
    id SERIAL PRIMARY KEY,
    title  VARCHAR(20),
    body VARCHAR(200),
    created_at TIMESTAMP,
    updated_at TIMESTAMP,
    lock_revision INTEGER
);