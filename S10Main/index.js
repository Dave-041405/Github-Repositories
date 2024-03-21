function transferLoad() {
    // Get input values
    const sender = document.getElementById('sender').value;
    const receiver = document.getElementById('receiver').value;
    const amount = parseInt(document.getElementById('amount').value);

    // Perform validation
    if (sender === '' || receiver === '' || isNaN(amount) || amount <= 0) {
        document.getElementById('message').textContent = 'Please fill out all fields correctly.';
        return;
    }

    // Simulate transfer
    // In a real system, this would involve backend processing
    document.getElementById('message').textContent = `Load of ${amount} transferred from ${sender} to ${receiver}.`;
}
