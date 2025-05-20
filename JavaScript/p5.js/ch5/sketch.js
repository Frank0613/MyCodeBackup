let vehicle;

function setup() {
  createCanvas(windowWidth, windowHeight);

  const position = createVector(100, 100);
  const velocity = createVector();
  const maxSpeed = 8;
  const maxForce = 0.1;
  vehicle = Vehicle.create(position, velocity, maxSpeed, maxForce);
}

function draw() {
  clear();
  Vehicle.run(vehicle);
  Vehicle.update(vehicle);
  Vehicle.draw(vehicle, "#aaa");
}

const Vehicle = {
  create(position, velocity, maxSpeed, maxForce) {
    return { position, velocity, acceleration: createVector(), maxSpeed, maxForce };
  },

  update(v) {
    v.acceleration.limit(v.maxForce);
    v.velocity.add(v.acceleration);
    v.velocity.limit(v.maxSpeed);
    v.position.add(v.velocity);
    v.acceleration.set(0);
    Vehicle.adjustEdge(v);
  },

  adjustEdge(v) {
    if (v.position.x < 0) {
      v.position.x = 0;
      v.velocity.x *= -1;
    } else if (v.position.x >= width) {
      v.position.x = width - 1;
      v.velocity.x *= -1;
    }

    if (v.position.y < 0) {
      v.position.y = 0;
      v.velocity.y *= -1;
    } else if (v.position.y >= height) {
      v.position.y = height - 1;
      v.velocity.y *= -1;
    }
  },

  draw(v, strokeColor) {
    push();
    noFill();
    strokeWeight(2);
    stroke(strokeColor);
    translate(v.position);
    rotate(v.velocity.heading());
    beginShape();
    const r = 8;
    vertex(r * 2, 0);
    vertex(-r, r);
    vertex(-r, -r);
    endShape(CLOSE);
    pop();
  },

  run(v) {
    v.acceleration.set(10, 10);
  },
};